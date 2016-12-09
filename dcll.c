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
 * @param[in,out]   pstDcll �o�����z���X�g�\����
 * @retval          �Ȃ�
 */
void dcll_init(S_DCLL *pstDcll)
{
    pstDcll->pstPrev = pstDcll;
    pstDcll->pstNext = pstDcll;
}

/**
 * @fn
 * �o�����z���X�g�̏I��
 * @brief           �o�����z���X�g�̗v�f��j�����A�I������
 * @param[in,out]   pstDcll �o�����z���X�g�\����
 * @retval          �Ȃ�
 */
void dcll_term(S_DCLL *pstDcll)
{
    dcll_init(pstDcll);
}

/**
 * @fn
 * �o�����z���X�g�Ƀm�[�h��ǉ�
 * @brief           �o�����z���X�g�̖����Ƀm�[�h��ǉ�����
 * @param[in,out]   pstDcll �o�����z���X�g�\����
 * @param[in,out]   pstNode �ǉ�����m�[�h
 * @retval          �Ȃ�
 */
void dcll_append(S_DCLL *pstDcll, S_DCLL_NODE *pstNode)
{
    pstNode->pstPrev = pstDcll->pstPrev;
    pstNode->pstNext = pstDcll;
    pstDcll->pstPrev->pstNext = pstNode;
    pstDcll->pstPrev = pstNode;
}

/**
 * @fn
 * �o�����z���X�g�̃m�[�h���폜
 * @brief           �o�����z���X�g�̃m�[�h���폜����
 * @param[in,out]   pstDcll �o�����z���X�g�\����
 * @param[in,out]   pstNode �ǉ�����m�[�h
 * @retval          �Ȃ�
 */
void dcll_delete(S_DCLL_NODE *pstNode)
{
    pstNode->pstPrev->pstNext = pstNode->pstNext;
    pstNode->pstNext->pstPrev = pstNode->pstPrev;
    pstNode->pstPrev = pstNode;
    pstNode->pstNext = pstNode;
}

/**
 * @fn
 * �o�����z���X�g�̍ŏ��̃m�[�h���擾
 * @brief           �o�����z���X�g�̍ŏ��̃m�[�h���擾����
 * @param[in,out]   pstDcll �o�����z���X�g�\����
 * @retval          �Ȃ�
 */
S_DCLL_NODE volatile *dcll_get_first(S_DCLL *pstDcll)
{
    return pstDcll->pstPrev;
}

/**
 * @fn
 * �o�����z���X�g�ɗv�f��ǉ�
 * @brief           �v�f�̑O�ɗv�f��}������
 * @param[in,out]   pstNode     �Ώۂ̃m�[�h
 * @param[in,out]   pstEntry    �ǉ�����G���g���[
 * @retval          �Ȃ�
 */
void dcll_insert_prev(S_DCLL_NODE *pstNode, S_DCLL_NODE *pstEntry)
{
    pstEntry->pstPrev = pstNode->pstPrev;
    pstEntry->pstNext = pstNode;
    pstNode->pstPrev->pstNext = pstEntry;
    pstNode->pstPrev = pstEntry;
}

/**
 * @fn
 * �o�����z���X�g�ɗv�f��ǉ�
 * @brief           �v�f�̌��ɗv�f��}������
 * @param[in,out]   pstNode     �Ώۂ̃m�[�h
 * @param[in,out]   pstEntry    �ǉ�����G���g���[
 * @retval          �Ȃ�
 */
void dcll_insert_next(S_DCLL_NODE *pstNode, S_DCLL_NODE *pstEntry)
{
    pstEntry->pstPrev = pstNode;
    pstEntry->pstNext = pstNode->pstNext;
    pstNode->pstNext->pstPrev = pstEntry;
    pstNode->pstNext = pstEntry;
}

/**
 * @fn
 * �o�����z���X�g�̏�Ԏ擾
 * @brief           �o�����z���X�g���󂩂ǂ����𒲂ׂ�
 * @param[in]       pstDcll �o�����z���X�g�\����
 * @retval          TRUE    �o�������X�g�͋�
 */
E_DCLL_STATE dcll_get_stat(S_DCLL *pstDcll)
{
    return ((pstDcll->pstPrev == pstDcll->pstNext) ? E_DCLL_STATE_EMPTY : E_DCLL_STATE_EXIST);
}

/* End of File */
