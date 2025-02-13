cmake_minimum_required(VERSION 3.22)

# 设置策略
if (POLICY CMP0123)
    cmake_policy(SET CMP0123 NEW)
endif ()

# 在project命令之前设置工具链
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/arm-none-eabi-toolchain.cmake)
set(COMMON_OPTIMIZATION_FLAGS "-O2")
# 项目名称
project(SubBoard
        VERSION 1.0.0
        LANGUAGES C CXX ASM
        DESCRIPTION "STM32H723 armclang_engineer Project"
)

# 确保使用正确的处理器设置
if (NOT CMAKE_SYSTEM_PROCESSOR STREQUAL "cortex-m7")
    message(FATAL_ERROR "CMAKE_SYSTEM_PROCESSOR must be set to cortex-m7")
endif ()

# 编译器标准
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 通用编译标志
set(COMMON_FLAGS "--target=arm-arm-none-eabi -mcpu=cortex-m7  -mfpu=fpv5-sp-d16 -mfloat-abi=hard ${COMMON_OPTIMIZATION_FLAGS}")

# 设置编译器标志
set(CMAKE_C_FLAGS "${COMMON_FLAGS} -c -xc -std=c99 -fno-rtti -funsigned-char -fshort-enums -fshort-wchar")
#set(CMAKE_CXX_FLAGS ${CMAKE_C_FLAGS})
set(CMAKE_CXX_FLAGS "${COMMON_FLAGS} -xc++ -std=c++20 -fno-rtti -fno-exceptions -funsigned-char -fshort-enums -fshort-wchar")
set(CMAKE_ASM_FLAGS "${COMMON_FLAGS} -masm=auto -Wa,--diag_suppress=A1950W")

# 链接器标志
set(CMAKE_EXE_LINKER_FLAGS
        "--cpu=Cortex-M7.fp.sp \
    --strict \
    --scatter \"${CMAKE_SOURCE_DIR}/MDK-ARM/${PROJECT_NAME}/${PROJECT_NAME}.sct\" \
    --summary_stderr --info summarysizes \
    --info sizes --info totals --info unused --info veneers \
    --list \"${CMAKE_BINARY_DIR}/${PROJECT_NAME}.map\""
)


# 添加头文件路径
include_directories(
        Core/Inc
#        USB_DEVICE/App
#        USB_DEVICE/Target
        Drivers/STM32H7xx_HAL_Driver/Inc
        Drivers/STM32H7xx_HAL_Driver/Inc/Legacy
        Middlewares/Third_Party/FreeRTOS/Source/include
        Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS
        Middlewares/Third_Party/FreeRTOS/Source/portable/RVDS/ARM_CM4F
        Middlewares/ST/STM32_USB_Device_Library/Core/Inc
        Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc
        Drivers/CMSIS/Device/ST/STM32H7xx/Include
        Drivers/CMSIS/Include


        #        "D:/Keil_Pack/ARM/CMSIS-DSP/1.15.0/Include/dsp"
        #        "D:/Keil_Pack/ARM/CMSIS-DSP/1.15.0/Include"

        #        "D:/Keil_541_pack/ARM/CMSIS/6.1.0/CMSIS/Core/Include"
        #        "D:/Keil_541_pack/Keil/STM32F4xx_DFP/2.17.1/Drivers/CMSIS/Device/ST/STM32F4xx/Include"
        "Own/App"
        "Own/Bsp"
        "Own/Mod"
        "Own/Cbk"
)


# 获取源文件
file(GLOB_RECURSE SOURCES
        "MDK-ARM/*.s"
        "Core/Src/*.c"
        "Drivers/STM32H7xx_HAL_Driver/Src/*.c"
#        "USB_DEVICE/App/*.c"
#        "USB_DEVICE/Target/*.c"
        "Middlewares/Third_Party/FreeRTOS/Source/*.c"
        "Middlewares/Third_Party/FreeRTOS/Source/portable/RVDS/ARM_CM4F/*.c"
        "Middlewares/Third_Party/FreeRTOS/Source/portable/MemMang/*.c"
        "Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/*.c"
        "Middlewares/ST/STM32_USB_Device_Library/Core/Src/*.c"
        "Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Src/*.c"
)
#        "D:/Keil_Pack/ARM/CMSIS-DSP/1.15.0/Source/*/arm*"
file(GLOB_RECURSE OWN_SOURCES
        "Own/Cbk/*.c" "Own/Cbk/*.cpp"
        "Own/App/*.c" "Own/App/*.cpp"
        "Own/Bsp/*.c" "Own/Bsp/*.cpp"
        "Own/Mod/*.c" "Own/Mod/*.cpp"
        "Own/Task/*.c" "Own/Task/*.cpp"
#        "Own/Obj/*.c" "Own/Obj/*.cpp"
#        "Own/OperateSystem/*.c" "Own/OperateSystem/*.cpp"
)

# 创建可执行文件
add_executable(${PROJECT_NAME} ${SOURCES} ${OWN_SOURCES})
## 设置CMSIS-DSP的根目录
#set(CMSIS_DSP_ROOT "D:/Keil_Pack/ARM/CMSIS-DSP/1.15.0")
#
## 设置静态库的输出路径
#set(CMSIS_DSP_LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/libs")
#file(MAKE_DIRECTORY ${CMSIS_DSP_LIB_DIR})
#
## 检查静态库是否已经存在
#set(CMSIS_DSP_STATIC_LIB "${CMSIS_DSP_LIB_DIR}/libCMSISDSP.a")
#
#if (NOT EXISTS ${CMSIS_DSP_STATIC_LIB})
#    message(STATUS "CMSIS-DSP static library not found, building it...")
#
#    # 创建DSP源文件列表
#    set(DSP_MODULES
#            BasicMathFunctions
#            CommonTables
#            ComplexMathFunctions
#            ControllerFunctions
#            DistanceFunctions
#            FastMathFunctions
#            FilteringFunctions
#            MatrixFunctions
#            StatisticsFunctions
#            SupportFunctions
#            TransformFunctions
#            BayesFunctions
#            SVMFunctions
#            InterpolationFunctions
#    )
#
#    # 收集所有DSP源文件
#    set(CMSIS_DSP_SOURCES "")
#    foreach (MODULE ${DSP_MODULES})
#        file(GLOB MODULE_SOURCES
#                "${CMSIS_DSP_ROOT}/Source/${MODULE}/*.c"
#                "${CMSIS_DSP_ROOT}/Source/${MODULE}/arm_*.c"
#        )
#        list(APPEND CMSIS_DSP_SOURCES ${MODULE_SOURCES})
#    endforeach ()
#
#    # 直接在当前目录创建静态库
#    add_library(CMSISDSP STATIC ${CMSIS_DSP_SOURCES})
#
#    # 设置CMSIS-DSP编译选项
#    set(NEON OFF CACHE BOOL "Neon acceleration")
#    set(NEONEXPERIMENTAL OFF CACHE BOOL "Neon experimental acceleration")
#    set(HELIUMEXPERIMENTAL OFF CACHE BOOL "Helium experimental acceleration")
#    set(LOOPUNROLL ON CACHE BOOL "Loop unrolling")
#    set(ROUNDING ON CACHE BOOL "Rounding")
#    set(MATRIXCHECK ON CACHE BOOL "Matrix Checks")
#    set(HELIUM OFF CACHE BOOL "Helium acceleration")
#    set(MVEF OFF CACHE BOOL "MVEF intrinsics")
#    set(MVEI OFF CACHE BOOL "MVEI intrinsics")
#    set(MVEFLOAT16 OFF CACHE BOOL "Float16 MVE intrinsics")
#    set(DISABLEFLOAT16 OFF CACHE BOOL "Disable float16")
#    set(HOST OFF CACHE BOOL "Host build")
#    set(AUTOVECTORIZE OFF CACHE BOOL "Autovectorize")
#    set(LAXVECTORCONVERSIONS ON CACHE BOOL "Lax vector conversions")
#
#    # 设置CMSIS-DSP的编译选项
#    target_compile_options(CMSISDSP PRIVATE
#            ${COMMON_FLAGS}
#            -mfloat-abi=hard
#            -mfpu=fpv5-sp-d16
#    )
#
#    # 设置CMSIS-DSP的编译定义
#    target_compile_definitions(CMSISDSP PRIVATE
#            ARM_MATH_CM7
#            __FPU_PRESENT=1U
#            ARM_MATH_MATRIX_CHECK
#            ARM_MATH_ROUNDING
#            ARM_MATH_LOOPUNROLL
#    )
#
#    # 设置CMSIS-DSP的包含目录
#    target_include_directories(CMSISDSP PRIVATE
#            ${CMSIS_DSP_ROOT}/Include
#            ${CMSIS_DSP_ROOT}/PrivateInclude
#    )
#
#    # 设置CMSIS-DSP的输出路径和名称
#    set_target_properties(CMSISDSP PROPERTIES
#            ARCHIVE_OUTPUT_DIRECTORY "${CMSIS_DSP_LIB_DIR}"
#            OUTPUT_NAME "CMSISDSP"
#    )
#
#    # 添加编译完成后的复制命令
#    add_custom_command(TARGET CMSISDSP POST_BUILD
#            COMMAND ${CMAKE_COMMAND} -E copy
#            "$<TARGET_FILE:CMSISDSP>"
#            "${CMSIS_DSP_STATIC_LIB}"
#            COMMENT "Copying CMSIS-DSP static library to libs directory"
#    )
#else ()
#    message(STATUS "Using pre-built CMSIS-DSP static library from ${CMSIS_DSP_STATIC_LIB}")
#
#    # 创建一个导入的库目标
#    add_library(CMSISDSP STATIC IMPORTED GLOBAL)
#    set_target_properties(CMSISDSP PROPERTIES
#            IMPORTED_LOCATION "${CMSIS_DSP_STATIC_LIB}"
#    )
#endif ()
#
#
## 添加CMSIS-DSP的头文件路径到主项目
#target_include_directories(${PROJECT_NAME} PRIVATE
#        ${CMSIS_DSP_ROOT}/Include
#        ${CMSIS_DSP_ROOT}/PrivateInclude
#)
#
#
## 链接CMSIS-DSP库
#target_link_libraries(${PROJECT_NAME} PRIVATE CMSISDSP)
#
#
# 为主项目添加编译定义
target_compile_definitions(${PROJECT_NAME} PRIVATE
        ARM_MATH_CM7
        __FPU_PRESENT=1U
        ARM_MATH_MATRIX_CHECK
        ARM_MATH_ROUNDING
        USE_HAL_DRIVER
        STM32H723xx
)
#
## 确保CMSIS-DSP库在主项目之前构建
#add_dependencies(${PROJECT_NAME} CMSISDSP)


# 设置输出文件扩展名
set_target_properties(${PROJECT_NAME} PROPERTIES
        SUFFIX ".axf"
)

# 生成hex和bin文件
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${TOOLCHAIN_PATH}/fromelf.exe --i32combined --output="${CMAKE_BINARY_DIR}/${PROJECT_NAME}.hex" "${CMAKE_BINARY_DIR}/${PROJECT_NAME}.axf"
        COMMAND ${TOOLCHAIN_PATH}/fromelf.exe --bin --output="${CMAKE_BINARY_DIR}/${PROJECT_NAME}.bin" "${CMAKE_BINARY_DIR}/${PROJECT_NAME}.axf"
        COMMENT "Building ${PROJECT_NAME}.hex and ${PROJECT_NAME}.bin"
)
# 可视化内存占用
set(ARMCC_CALCELF "${CMAKE_SOURCE_DIR}/calcelf.exe")
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${ARMCC_CALCELF} -m "${CMAKE_SOURCE_DIR}/MDK-ARM/${PROJECT_NAME}/${PROJECT_NAME}.map" -s "${CMAKE_SOURCE_DIR}/MDK-ARM/${PROJECT_NAME}/${PROJECT_NAME}.sct"
        COMMAND ${ARMCC_CALCELF} --format=progbar --map="${CMAKE_SOURCE_DIR}/MDK-ARM/${PROJECT_NAME}/${PROJECT_NAME}.map"
        --scatter="${CMAKE_SOURCE_DIR}/MDK-ARM/${PROJECT_NAME}/${PROJECT_NAME}.sct"
)
