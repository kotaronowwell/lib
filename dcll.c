/**
 * @file        dcll.c
 * @brief       Doubly-circularly-linked-list
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

#include "dcll.h"

/**
 * @fn
 * �o�����z���X�g�̏�����
 * @brief           �o�����z���X�g�̏��������s��
 * @param[in,out]   pDcll �o�����z���X�g�\����
 * @retval          �Ȃ�
 */
void dcll_init(DCLL *pDcll)
{
    pDcll->pPrev = pDcll;
    pDcll->pNext = pDcll;
}

/**
 * @fn
 * �o�����z���X�g�̏I��
 * @brief           �o�����z���X�g�̗v�f��j�����A�I������
 * @param[in,out]   pDcll �o�����z���X�g�\����
 * @retval          �Ȃ�
 */
void dcll_term(DCLL *pDcll)
{
    dcll_init(pDcll);
}

/**
 * @fn
 * �o�����z���X�g�Ƀm�[�h��ǉ�
 * @brief           �o�����z���X�g�̖����Ƀm�[�h��ǉ�����
 * @param[in,out]   pDcll �o�����z���X�g�\����
 * @param[in,out]   pNode �ǉ�����m�[�h
 * @retval          �Ȃ�
 */
void dcll_append(DCLL *pDcll, DCLL_NODE *pNode)
{
    pNode->pPrev = pDcll->pPrev;
    pNode->pNext = pDcll;
    pDcll->pPrev->pNext = pNode;
    pDcll->pPrev = pNode;
}

/**
 * @fn
 * �o�����z���X�g�Ƀm�[�h��ǉ�
 * @brief           �o�����z���X�g�̐擪�Ƀm�[�h��ǉ�����
 * @param[in,out]   pDcll �o�����z���X�g�\����
 * @param[in,out]   pNode �ǉ�����m�[�h
 * @retval          �Ȃ�
 */
void dcll_prepend(DCLL *pDcll, DCLL_NODE *pNode)
{
    pNode->pPrev = pDcll;
    pNode->pNext = pDcll->pNext;
    pDcll->pNext->pPrev = pNode;
    pDcll->pPrev = pNode;
}

/**
 * @fn
 * �o�����z���X�g�̃m�[�h���폜
 * @brief           �o�����z���X�g�̃m�[�h���폜����
 * @param[in,out]   pDcll �o�����z���X�g�\����
 * @param[in,out]   pNode �ǉ�����m�[�h
 * @retval          �Ȃ�
 */
void dcll_delete(DCLL_NODE *pNode)
{
    pNode->pPrev->pNext = pNode->pNext;
    pNode->pNext->pPrev = pNode->pPrev;
    pNode->pPrev = pNode;
    pNode->pNext = pNode;
}

/**
 * @fn
 * �o�����z���X�g�̍ŏ��̃m�[�h���擾
 * @brief           �o�����z���X�g�̍ŏ��̃m�[�h���擾����
 * @param[in,out]   pDcll �o�����z���X�g�\����
 * @retval          �Ȃ�
 */
DCLL_NODE volatile *dcll_get_first(DCLL *pDcll)
{
    return pDcll->pPrev;
}

/**
 * @fn
 * �o�����z���X�g�ɗv�f��ǉ�
 * @brief           �v�f�̑O�ɗv�f��}������
 * @param[in,out]   pNode     �Ώۂ̃m�[�h
 * @param[in,out]   pEntry    �ǉ�����G���g���[
 * @retval          �Ȃ�
 */
void dcll_ins_prev(DCLL_NODE *pNode, DCLL_NODE *pEntry)
{
    pEntry->pPrev = pNode->pPrev;
    pEntry->pNext = pNode;
    pNode->pPrev->pNext = pEntry;
    pNode->pPrev = pEntry;
}

/**
 * @fn
 * �o�����z���X�g�ɗv�f��ǉ�
 * @brief           �v�f�̌��ɗv�f��}������
 * @param[in,out]   pNode     �Ώۂ̃m�[�h
 * @param[in,out]   pEntry    �ǉ�����G���g���[
 * @retval          �Ȃ�
 */
void dcll_ins_next(DCLL_NODE *pNode, DCLL_NODE *pEntry)
{
    pEntry->pPrev = pNode;
    pEntry->pNext = pNode->pNext;
    pNode->pNext->pPrev = pEntry;
    pNode->pNext = pEntry;
}

/**
 * @fn
 * �o�����z���X�g�̏�Ԏ擾
 * @brief           �o�����z���X�g���󂩂ǂ����𒲂ׂ�
 * @param[in]       pDcll �o�����z���X�g�\����
 * @retval          DCLL_STATE_EMPTY    �o�������X�g�͋�
 * @retval          DCLL_STATE_EXIST    �o�������X�g�͋�łȂ�
 */
DCLL_STATE dcll_get_state(DCLL_NODE *pDcll)
{
    return ((pDcll->pPrev == pDcll->pNext) ? DCLL_STATE_EMPTY : DCLL_STATE_EXIST);
}

/* End of File */
