/**
 * @file        lifo.c
 * @brief       Last-in-first-out
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

#include "lifo.h"

/**
 * @fn
 * LIFOノードの初期化
 * @brief           LIFOノードの初期化を行う
 * @param[in,out]   pstLifo LIFOノード構造体
 * @retval          なし
 */
void lifo_node_init(S_LIFO_NODE *pstNode)
{
    pstNode->pstPrev = 0;
}

/**
 * @fn
 * LIFOノードの終了
 * @brief           LIFOノードの終了処理を行う
 * @param[in,out]   pstLifo LIFOノード構造体
 * @retval          なし
 */
void lifo_node_term(S_LIFO_NODE *pstNode)
{
    lifo_node_init(pstNode);
}

/**
 * @fn
 * LIFOの初期化
 * @brief           LIFOの初期化を行う
 * @param[in,out]   pstLifo LIFO構造体
 * @retval          なし
 */
void lifo_init(S_LIFO *pstLifo)
{
    lifo_node_init((S_LIFO *)pstLifo);
}

/**
 * @fn
 * LIFOの終了
 * @brief           LIFOの終了処理を行う
 * @param[in,out]   pstLifo LIFO構造体
 * @retval          なし
 */
void lifo_term(S_LIFO *pstLifo)
{
    lifo_init(pstLifo);
}

/**
 * @fn
 * LIFOの先頭ノードを取得する
 * @brief           LIFOの先頭ノードを調べる
 * @param[in,out]   pstLifo LIFO構造体
 * @retval          なし
 */
volatile S_LIFO_NODE *lifo_get_top(S_LIFO *pstLifo)
{
    return pstLifo->pstPrev;
}

/**
 * @fn
 * LIFOにノードをプッシュする
 * @brief           LIFOにノードをプッシュする処理を行う
 * @param[in,out]   pstLifo LIFO構造体
 * @param[in,out]   pstNode プッシュするLIFOノード
 * @retval          なし
 */
void lifo_push(S_LIFO *pstLifo, S_LIFO_NODE *pstNode)
{
    pstNode->pstPrev = pstLifo->pstPrev;
    pstLifo->pstPrev = pstNode;
}

/**
 * @fn
 * LIFOのノードをポップする
 * @brief           LIFOのノードをポップする処理を行う
 * @param[in,out]   pstLifo LIFO構造体
 * @retval          ポップされたLIFOノード
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
 * LIFOの状態を調べる
 * @brief           LIFOのノードをポップする処理を行う
 * @param[in,out]   pstLifo LIFO構造体
 * @retval          TRUE    LIFOは空
 * @retval          FALSE   LIFOは空でない
 */
E_LIFO_STATE lifo_get_stat(S_LIFO *pstLifo)
{
    return ((pstLifo->pstPrev == 0) ? E_LIFO_STATE_EMPTY : E_LIFO_STATE_EXIST);
}

/* End of File */
