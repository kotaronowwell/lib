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
 * @param[in,out]   pstLifo LIFO�m�[�h�\����
 * @retval          �Ȃ�
 */
void lifo_node_init(S_LIFO_NODE *pstNode)
{
    pstNode->pstPrev = 0;
}

/**
 * @fn
 * LIFO�m�[�h�̏I��
 * @brief           LIFO�m�[�h�̏I���������s��
 * @param[in,out]   pstLifo LIFO�m�[�h�\����
 * @retval          �Ȃ�
 */
void lifo_node_term(S_LIFO_NODE *pstNode)
{
    lifo_node_init(pstNode);
}

/**
 * @fn
 * LIFO�̏�����
 * @brief           LIFO�̏��������s��
 * @param[in,out]   pstLifo LIFO�\����
 * @retval          �Ȃ�
 */
void lifo_init(S_LIFO *pstLifo)
{
    lifo_node_init((S_LIFO *)pstLifo);
}

/**
 * @fn
 * LIFO�̏I��
 * @brief           LIFO�̏I���������s��
 * @param[in,out]   pstLifo LIFO�\����
 * @retval          �Ȃ�
 */
void lifo_term(S_LIFO *pstLifo)
{
    lifo_init(pstLifo);
}

/**
 * @fn
 * LIFO�̐擪�m�[�h���擾����
 * @brief           LIFO�̐擪�m�[�h�𒲂ׂ�
 * @param[in,out]   pstLifo LIFO�\����
 * @retval          �Ȃ�
 */
volatile S_LIFO_NODE *lifo_get_top(S_LIFO *pstLifo)
{
    return pstLifo->pstPrev;
}

/**
 * @fn
 * LIFO�Ƀm�[�h���v�b�V������
 * @brief           LIFO�Ƀm�[�h���v�b�V�����鏈�����s��
 * @param[in,out]   pstLifo LIFO�\����
 * @param[in,out]   pstNode �v�b�V������LIFO�m�[�h
 * @retval          �Ȃ�
 */
void lifo_push(S_LIFO *pstLifo, S_LIFO_NODE *pstNode)
{
    pstNode->pstPrev = pstLifo->pstPrev;
    pstLifo->pstPrev = pstNode;
}

/**
 * @fn
 * LIFO�̃m�[�h���|�b�v����
 * @brief           LIFO�̃m�[�h���|�b�v���鏈�����s��
 * @param[in,out]   pstLifo LIFO�\����
 * @retval          �|�b�v���ꂽLIFO�m�[�h
 */
volatile S_LIFO_NODE *lifo_pop(S_LIFO *pstLifo)
{
	volatile S_LIFO_NODE *pstNode;

    pstNode = lifo_get_top(pstLifo);
    pstLifo->pstPrev = pstLifo->pstPrev->pstPrev;

    return pstNode;
}

/**
 * @fn
 * LIFO�̏�Ԃ𒲂ׂ�
 * @brief           LIFO�̃m�[�h���|�b�v���鏈�����s��
 * @param[in,out]   pstLifo LIFO�\����
 * @retval          TRUE    LIFO�͋�
 * @retval          FALSE   LIFO�͋�łȂ�
 */
E_LIFO_STATE lifo_get_stat(S_LIFO *pstLifo)
{
    return ((pstLifo->pstPrev == 0) ? E_LIFO_STATE_EMPTY : E_LIFO_STATE_EXIST);
}

/* End of File */
