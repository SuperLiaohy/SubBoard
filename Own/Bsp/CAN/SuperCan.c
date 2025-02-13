//
// Created by liaohy on 9/5/24.
//

#include "SuperCan.h"


void can_init(SuperCan* self, FDCAN_HandleTypeDef* hcan) {
    self->hcan = hcan;
}

void can_filter_config(SuperCan* self, uint16_t filter_number, filter_mode filterMode, uint32_t reg_1, uint32_t reg_2) {
    FDCAN_FilterTypeDef sFilterConfig;
    sFilterConfig.IdType = FDCAN_STANDARD_ID;
    sFilterConfig.FilterIndex = filter_number;
    switch (filterMode) {
        case RANGE:
            sFilterConfig.FilterType = FDCAN_FILTER_RANGE;
            break;
        case MASK:
            sFilterConfig.FilterType = FDCAN_FILTER_MASK;
            break;
        case LIST:
            sFilterConfig.FilterType = FDCAN_FILTER_DUAL;
            break;
        default:
            break;
    }
    sFilterConfig.FilterConfig = FDCAN_FILTER_TO_RXFIFO0;
    sFilterConfig.FilterID1 = reg_1;
    sFilterConfig.FilterID2 = reg_2;

    if (HAL_FDCAN_ConfigFilter(self->hcan, &sFilterConfig) != HAL_OK) {
        Error_Handler();
    }
    HAL_FDCAN_ConfigGlobalFilter(self->hcan,FDCAN_REJECT,FDCAN_REJECT,FDCAN_REJECT_REMOTE,FDCAN_REJECT_REMOTE);
    HAL_FDCAN_ConfigFifoWatermark(self->hcan, FDCAN_CFG_RX_FIFO0, 1);
}

void can_start(SuperCan* self) {
    HAL_FDCAN_Start(self->hcan);
    HAL_FDCAN_ActivateNotification(self->hcan, FDCAN_IT_RX_FIFO0_NEW_MESSAGE, 0);
}

void can_send_pdata(SuperCan* self, uint32_t id, uint8_t* data) {
    self->tx_header.Identifier = id;
    self->tx_header.IdType = FDCAN_STANDARD_ID;
    self->tx_header.TxFrameType = FDCAN_DATA_FRAME;
    self->tx_header.DataLength = 8;
    self->tx_header.ErrorStateIndicator = FDCAN_ESI_ACTIVE;
    self->tx_header.BitRateSwitch = FDCAN_BRS_OFF;
    self->tx_header.FDFormat = FDCAN_CLASSIC_CAN;
    self->tx_header.TxEventFifoControl = FDCAN_NO_TX_EVENTS;
    self->tx_header.MessageMarker = 0;
    if (HAL_FDCAN_AddMessageToTxFifoQ(self->hcan, &self->tx_header, data) != HAL_OK) { return; }
}

void can_send_data(SuperCan *self, uint32_t id, int16_t data1, int16_t data2, int16_t data3, int16_t data4) {
    self->tx_data[0] = (uint8_t)(data1 >> 8);
    self->tx_data[1] = (uint8_t)(data1);
    self->tx_data[2] = (uint8_t)(data2 >> 8);
    self->tx_data[3] = (uint8_t)(data2);
    self->tx_data[4] = (uint8_t)(data3 >> 8);
    self->tx_data[5] = (uint8_t)(data3);
    self->tx_data[6] = (uint8_t)(data4 >> 8);
    self->tx_data[7] = (uint8_t)(data4);
    can_send_pdata(self, id, self->tx_data);
}

void can_receive(SuperCan *self) {
    HAL_FDCAN_GetRxMessage(self->hcan, FDCAN_RX_FIFO0, &self->rx_header, self->rx_data);
}

void can_receive_pdata(SuperCan *self, uint8_t *data) {
    HAL_FDCAN_GetRxMessage(self->hcan, FDCAN_RX_FIFO0, &self->rx_header, data);
}
