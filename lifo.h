/**
 * @file    lifo.h
 * @brief   Last-in-first-out
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

#ifndef LIFO_H
#define LIFO_H

typedef struct tagS_LIFO {
    struct tagS_LIFO volatile *pstPrev;
} S_LIFO, S_LIFO_NODE;

typedef enum tagE_LIFO_STATE {
    E_LIFO_STATE_EMPTY,     /**< Last-in-first-out empty        */
    E_LIFO_STATE_EXIST      /**< Last-in-first-out not empty    */
} E_LIFO_STATE;

#ifdef __cpulspuls
extern "C" {
#endif /* __cpulspuls */

void lifo_node_init(S_LIFO_NODE *pstNode);
void lifo_node_term(S_LIFO_NODE *pstNode);
void lifo_init(S_LIFO *pstLifo);
void lifo_term(S_LIFO *pstLifo);
volatile S_LIFO_NODE *lifo_get_top(S_LIFO *pstLifo);
void lifo_push(S_LIFO *pstLifo, S_LIFO_NODE *pstNode);
volatile S_LIFO_NODE *lifo_pop(S_LIFO *pstLifo);
E_LIFO_STATE lifo_get_stat(S_LIFO *pstLifo);

#ifdef __cpulspuls
}
#endif /* __cpulspuls */

#endif /* LIFO_H */
