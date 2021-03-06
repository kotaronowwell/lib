/**
 * @file        dcll.c
 * @brief       Doubly-circularly-linked-list
 * @author      Kimai
 * @date        04-May-2016
 * @attention   エラーチェックは省略
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
 * 双方向循環リストの初期化
 * @brief           双方向循環リストの初期化を行う
 * @param[in,out]   pDcll 双方向循環リスト構造体
 * @retval          なし
 */
void dcll_init(DCLL *pDcll)
{
    pDcll->pPrev = pDcll;
    pDcll->pNext = pDcll;
}

/**
 * @fn
 * 双方向循環リストの終了
 * @brief           双方向循環リストの要素を破棄し、終了する
 * @param[in,out]   pDcll 双方向循環リスト構造体
 * @retval          なし
 */
void dcll_term(DCLL *pDcll)
{
    dcll_init(pDcll);
}

/**
 * @fn
 * 双方向循環リストにノードを追加
 * @brief           双方向循環リストの末尾にノードを追加する
 * @param[in,out]   pDcll 双方向循環リスト構造体
 * @param[in,out]   pNode 追加するノード
 * @retval          なし
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
 * 双方向循環リストにノードを追加
 * @brief           双方向循環リストの先頭にノードを追加する
 * @param[in,out]   pDcll 双方向循環リスト構造体
 * @param[in,out]   pNode 追加するノード
 * @retval          なし
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
 * 双方向循環リストのノードを削除
 * @brief           双方向循環リストのノードを削除する
 * @param[in,out]   pDcll 双方向循環リスト構造体
 * @param[in,out]   pNode 追加するノード
 * @retval          なし
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
 * 双方向循環リストの最初のノードを取得
 * @brief           双方向循環リストの最初のノードを取得する
 * @param[in,out]   pDcll 双方向循環リスト構造体
 * @retval          なし
 */
DCLL_NODE volatile *dcll_get_first(DCLL *pDcll)
{
    return pDcll->pPrev;
}

/**
 * @fn
 * 双方向循環リストに要素を追加
 * @brief           要素の前に要素を挿入する
 * @param[in,out]   pNode     対象のノード
 * @param[in,out]   pEntry    追加するエントリー
 * @retval          なし
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
 * 双方向循環リストに要素を追加
 * @brief           要素の後ろに要素を挿入する
 * @param[in,out]   pNode     対象のノード
 * @param[in,out]   pEntry    追加するエントリー
 * @retval          なし
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
 * 双方向循環リストの状態取得
 * @brief           双方向循環リストが空かどうかを調べる
 * @param[in]       pDcll 双方向循環リスト構造体
 * @retval          DCLL_STATE_EMPTY    双方向リストは空
 * @retval          DCLL_STATE_EXIST    双方向リストは空でない
 */
DCLL_STATE dcll_get_state(DCLL_NODE *pDcll)
{
    return ((pDcll->pPrev == pDcll->pNext) ? DCLL_STATE_EMPTY : DCLL_STATE_EXIST);
}

/* End of File */
