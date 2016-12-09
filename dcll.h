/**
 * @file    dcll.h
 * @brief   Doubly-circularly-linked-list
 * @author  Kimai
 * @date    04-May-2016
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

#ifndef DCLL_H
#define DCLL_H

typedef struct tagS_DCLL {
    struct tagS_DCLL volatile *pstPrev;
    struct tagS_DCLL volatile *pstNext;
} S_DCLL, S_DCLL_NODE;

typedef enum tagE_DCLL_STATE {
    E_DCLL_STATE_EMPTY,     /**< Doubly-circularly-linked-list empty        */
    E_DCLL_STATE_EXIST      /**< Doubly-circularly-linked-list not empty    */
} E_DCLL_STATE;

#ifdef __cpulspuls
extern "C" {
#endif /* __cpulspuls */

void dcll_init(S_DCLL *pstDcll);
void dcll_term(S_DCLL *pstDcll);
void dcll_append(S_DCLL *pstDcll, S_DCLL_NODE *pstNode);
void dcll_prepend(S_DCLL *pstDcll, S_DCLL_NODE *pstNode);
void dcll_delete(S_DCLL_NODE *pstNode);
S_DCLL_NODE volatile *dcll_get_first(S_DCLL *pstDcll);
void dcll_insert_prev(S_DCLL_NODE *pstNode, S_DCLL_NODE *pstEntry);
void dcll_insert_next(S_DCLL_NODE *pstNode, S_DCLL_NODE *pstEntry);
E_DCLL_STATE dcll_get_stat(S_DCLL_NODE *pstDcll);

#ifdef __cpulspuls
}
#endif /* __cpulspuls */

#endif /* DCLL_H */
