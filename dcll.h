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

typedef struct tagDCLL {
    struct tagDCLL volatile *pPrev;
    struct tagDCLL volatile *pNext;
} DCLL, DCLL_NODE;

typedef enum tagDCLL_STATE {
    DCLL_STATE_EMPTY,       /**< Doubly-circularly-linked-list empty        */
    DCLL_STATE_EXIST        /**< Doubly-circularly-linked-list not empty    */
} DCLL_STATE;

#ifdef __cpulspuls
extern "C" {
#endif /* __cpulspuls */

void dcll_init(DCLL *pDcll);
void dcll_term(DCLL *pDcll);
void dcll_append(DCLL *pDcll, DCLL_NODE *pNode);
void dcll_prepend(DCLL *pDcll, DCLL_NODE *pNode);
void dcll_delete(DCLL_NODE *pNode);
DCLL_NODE volatile *dcll_get_first(DCLL *pDcll);
void dcll_ins_prev(DCLL_NODE *pNode, DCLL_NODE *pEntry);
void dcll_ins_next(DCLL_NODE *pNode, DCLL_NODE *pEntry);
DCLL_STATE dcll_get_state(DCLL_NODE *pDcll);

#ifdef __cpulspuls
}
#endif /* __cpulspuls */

#endif /* DCLL_H */
