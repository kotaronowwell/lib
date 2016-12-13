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
 * @param[in,out]   pLifo LIFOノード構造体
 * @retval          なし
 */
void lifo_node_init(LIFO_NODE *pNode)
{
    pNode->pPrev = 0;
}

/**
 * @fn
 * LIFOノードの終了
 * @brief           LIFOノードの終了処理を行う
 * @param[in,out]   pLifo LIFOノード構造体
 * @retval          なし
 */
void lifo_node_term(LIFO_NODE *pNode)
{
    lifo_node_init(pNode);
}

/**
 * @fn
 * LIFOの初期化
 * @brief           LIFOの初期化を行う
 * @param[in,out]   pLifo LIFO構造体
 * @retval          なし
 */
void lifo_init(LIFO *pLifo)
{
    lifo_node_init((LIFO *)pLifo);
}

/**
 * @fn
 * LIFOの終了
 * @brief           LIFOの終了処理を行う
 * @param[in,out]   pLifo LIFO構造体
 * @retval          なし
 */
void lifo_term(LIFO *pLifo)
{
    lifo_init(pLifo);
}

/**
 * @fn
 * LIFOの先頭ノードを取得する
 * @brief           LIFOの先頭ノードを調べる
 * @param[in,out]   pLifo LIFO構造体
 * @retval          なし
 */
volatile LIFO_NODE *lifo_get_top(LIFO *pLifo)
{
    return pLifo->pPrev;
}

/**
 * @fn
 * LIFOにノードをプッシュする
 * @brief           LIFOにノードをプッシュする処理を行う
 * @param[in,out]   pLifo LIFO構造体
 * @param[in,out]   pNode プッシュするLIFOノード
 * @retval          なし
 */
void lifo_push(LIFO *pLifo, LIFO_NODE *pNode)
{
    pNode->pPrev = pLifo->pPrev;
    pLifo->pPrev = pNode;
}

/**
 * @fn
 * LIFOのノードをポップする
 * @brief           LIFOのノードをポップする処理を行う
 * @param[in,out]   pLifo LIFO構造体
 * @retval          ポップされたLIFOノード
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
 * LIFOの状態を調べる
 * @brief           LIFOのノードをポップする処理を行う
 * @param[in,out]   pLifo LIFO構造体
 * @retval          LIFO_STATE_EMPTY    LIFOは空
 * @retval          LIFO_STATE_EXIST    LIFOは空でない
 */
LIFO_STATE lifo_get_stat(LIFO *pLifo)
{
    return ((pLifo->pPrev == 0) ? LIFO_STATE_EMPTY : LIFO_STATE_EXIST);
}

/* End of File */
