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
 * @param[in,out]   pstDcll 双方向循環リスト構造体
 * @retval          なし
 */
void dcll_init(S_DCLL *pstDcll)
{
    pstDcll->pstPrev = pstDcll;
    pstDcll->pstNext = pstDcll;
}

/**
 * @fn
 * 双方向循環リストの終了
 * @brief           双方向循環リストの要素を破棄し、終了する
 * @param[in,out]   pstDcll 双方向循環リスト構造体
 * @retval          なし
 */
void dcll_term(S_DCLL *pstDcll)
{
    dcll_init(pstDcll);
}

/**
 * @fn
 * 双方向循環リストにノードを追加
 * @brief           双方向循環リストの末尾にノードを追加する
 * @param[in,out]   pstDcll 双方向循環リスト構造体
 * @param[in,out]   pstNode 追加するノード
 * @retval          なし
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
 * 双方向循環リストのノードを削除
 * @brief           双方向循環リストのノードを削除する
 * @param[in,out]   pstDcll 双方向循環リスト構造体
 * @param[in,out]   pstNode 追加するノード
 * @retval          なし
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
 * 双方向循環リストの最初のノードを取得
 * @brief           双方向循環リストの最初のノードを取得する
 * @param[in,out]   pstDcll 双方向循環リスト構造体
 * @retval          なし
 */
S_DCLL_NODE volatile *dcll_get_first(S_DCLL *pstDcll)
{
    return pstDcll->pstPrev;
}

/**
 * @fn
 * 双方向循環リストに要素を追加
 * @brief           要素の前に要素を挿入する
 * @param[in,out]   pstNode     対象のノード
 * @param[in,out]   pstEntry    追加するエントリー
 * @retval          なし
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
 * 双方向循環リストに要素を追加
 * @brief           要素の後ろに要素を挿入する
 * @param[in,out]   pstNode     対象のノード
 * @param[in,out]   pstEntry    追加するエントリー
 * @retval          なし
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
 * 双方向循環リストの状態取得
 * @brief           双方向循環リストが空かどうかを調べる
 * @param[in]       pstDcll 双方向循環リスト構造体
 * @retval          TRUE    双方向リストは空
 */
E_DCLL_STATE dcll_get_stat(S_DCLL *pstDcll)
{
    return ((pstDcll->pstPrev == pstDcll->pstNext) ? E_DCLL_STATE_EMPTY : E_DCLL_STATE_EXIST);
}

/* End of File */
