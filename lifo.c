/**
 * @file        lifo.c
 * @brief       Last-in-first-out
 * @author      Kimai
 * @date        04-May-2016
 * @attention   �G���[�`�F�b�N�͏ȗ�
 */
/*------------------------------------------------------------------------*/
/*
 * Copyright (C) 2016, Kimai, all right reserved.
 *
 * This software is a free software and there is NO WARRANTY.
 * No restriction on use. You can use, modify and redistribute it for
 * personal, non-profit or commercial products UNDER YOUR RESPONSIBILITY.
 * Redistributions of source code must retain the above copyright notice.
 */
/*------------------------------------------------------------------------*/

#include "lifo.h"

/**
 * @fn
 * LIFO�m�[�h�̏�����
 * @brief           LIFO�m�[�h�̏��������s��
 * @param[in,out]   pLifo LIFO�m�[�h�\����
 * @retval          �Ȃ�
 */
void lifo_node_init(LIFO_NODE *pNode)
{
    pNode->pPrev = 0;
}

/**
 * @fn
 * LIFO�m�[�h�̏I��
 * @brief           LIFO�m�[�h�̏I���������s��
 * @param[in,out]   pLifo LIFO�m�[�h�\����
 * @retval          �Ȃ�
 */
void lifo_node_term(LIFO_NODE *pNode)
{
    lifo_node_init(pNode);
}

/**
 * @fn
 * LIFO�̏�����
 * @brief           LIFO�̏��������s��
 * @param[in,out]   pLifo LIFO�\����
 * @retval          �Ȃ�
 */
void lifo_init(LIFO *pLifo)
{
    lifo_node_init((LIFO *)pLifo);
}

/**
 * @fn
 * LIFO�̏I��
 * @brief           LIFO�̏I���������s��
 * @param[in,out]   pLifo LIFO�\����
 * @retval          �Ȃ�
 */
void lifo_term(LIFO *pLifo)
{
    lifo_init(pLifo);
}

/**
 * @fn
 * LIFO�̐擪�m�[�h���擾����
 * @brief           LIFO�̐擪�m�[�h�𒲂ׂ�
 * @param[in,out]   pLifo LIFO�\����
 * @retval          �Ȃ�
 */
volatile LIFO_NODE *lifo_get_top(LIFO *pLifo)
{
    return pLifo->pPrev;
}

/**
 * @fn
 * LIFO�Ƀm�[�h���v�b�V������
 * @brief           LIFO�Ƀm�[�h���v�b�V�����鏈�����s��
 * @param[in,out]   pLifo LIFO�\����
 * @param[in,out]   pNode �v�b�V������LIFO�m�[�h
 * @retval          �Ȃ�
 */
void lifo_push(LIFO *pLifo, LIFO_NODE *pNode)
{
    pNode->pPrev = pLifo->pPrev;
    pLifo->pPrev = pNode;
}

/**
 * @fn
 * LIFO�̃m�[�h���|�b�v����
 * @brief           LIFO�̃m�[�h���|�b�v���鏈�����s��
 * @param[in,out]   pLifo LIFO�\����
 * @retval          �|�b�v���ꂽLIFO�m�[�h
 */
volatile LIFO_NODE *lifo_pop(LIFO *pLifo)
{
	volatile LIFO_NODE *pNode;

    pNode = lifo_get_top(pLifo);
    pLifo->pPrev = pLifo->pPrev->pPrev;

    return pNode;
}

/**
 * @fn
 * LIFO�̏�Ԃ𒲂ׂ�
 * @brief           LIFO�̃m�[�h���|�b�v���鏈�����s��
 * @param[in,out]   pLifo LIFO�\����
 * @retval          LIFO_STATE_EMPTY    LIFO�͋�
 * @retval          LIFO_STATE_EXIST    LIFO�͋�łȂ�
 */
LIFO_STATE lifo_get_stat(LIFO *pLifo)
{
    return ((pLifo->pPrev == 0) ? LIFO_STATE_EMPTY : LIFO_STATE_EXIST);
}

/* End of File */
