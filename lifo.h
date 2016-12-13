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

typedef struct tagLIFO {
    struct tagLIFO volatile *pPrev;
} LIFO, LIFO_NODE;

typedef enum tagLIFO_STATE {
    LIFO_STATE_EMPTY,       /**< Last-in-first-out empty        */
    LIFO_STATE_EXIST        /**< Last-in-first-out not empty    */
} LIFO_STATE;

#ifdef __cpulspuls
extern "C" {
#endif /* __cpulspuls */

void lifo_node_init(LIFO_NODE *pNode);
void lifo_node_term(LIFO_NODE *pNode);
void lifo_init(LIFO *pLifo);
void lifo_term(LIFO *pLifo);
volatile LIFO_NODE *lifo_get_top(LIFO *pLifo);
void lifo_push(LIFO *pLifo, LIFO_NODE *pNode);
volatile LIFO_NODE *lifo_pop(LIFO *pLifo);
LIFO_STATE lifo_get_stat(LIFO *pstLifo);

#ifdef __cpulspuls
}
#endif /* __cpulspuls */

#endif /* LIFO_H */
