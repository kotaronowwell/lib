/**
 * @file        dcll.c
 * @brief       Doubly-circularly-linked-list
 * @author      Kimai
 * @date        04-May-2016
 * @attention   ƒGƒ‰[ƒ`ƒFƒbƒN‚ÍÈ—ª
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
 * ‘o•ûŒüzŠÂƒŠƒXƒg‚Ì‰Šú‰»
 * @brief           ‘o•ûŒüzŠÂƒŠƒXƒg‚Ì‰Šú‰»‚ðs‚¤
 * @param[in,out]   pDcll ‘o•ûŒüzŠÂƒŠƒXƒg\‘¢‘Ì
 * @retval          ‚È‚µ
 */
void dcll_init(DCLL *pDcll)
{
    pDcll->pPrev = pDcll;
    pDcll->pNext = pDcll;
}

/**
 * @fn
 * ‘o•ûŒüzŠÂƒŠƒXƒg‚ÌI—¹
 * @brief           ‘o•ûŒüzŠÂƒŠƒXƒg‚Ì—v‘f‚ð”jŠü‚µAI—¹‚·‚é
 * @param[in,out]   pDcll ‘o•ûŒüzŠÂƒŠƒXƒg\‘¢‘Ì
 * @retval          ‚È‚µ
 */
void dcll_term(DCLL *pDcll)
{
    dcll_init(pDcll);
}

/**
 * @fn
 * ‘o•ûŒüzŠÂƒŠƒXƒg‚Éƒm[ƒh‚ð’Ç‰Á
 * @brief           ‘o•ûŒüzŠÂƒŠƒXƒg‚Ì––”ö‚Éƒm[ƒh‚ð’Ç‰Á‚·‚é
 * @param[in,out]   pDcll ‘o•ûŒüzŠÂƒŠƒXƒg\‘¢‘Ì
 * @param[in,out]   pNode ’Ç‰Á‚·‚éƒm[ƒh
 * @retval          ‚È‚µ
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
 * ‘o•ûŒüzŠÂƒŠƒXƒg‚Éƒm[ƒh‚ð’Ç‰Á
 * @brief           ‘o•ûŒüzŠÂƒŠƒXƒg‚Ìæ“ª‚Éƒm[ƒh‚ð’Ç‰Á‚·‚é
 * @param[in,out]   pDcll ‘o•ûŒüzŠÂƒŠƒXƒg\‘¢‘Ì
 * @param[in,out]   pNode ’Ç‰Á‚·‚éƒm[ƒh
 * @retval          ‚È‚µ
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
 * ‘o•ûŒüzŠÂƒŠƒXƒg‚Ìƒm[ƒh‚ðíœ
 * @brief           ‘o•ûŒüzŠÂƒŠƒXƒg‚Ìƒm[ƒh‚ðíœ‚·‚é
 * @param[in,out]   pDcll ‘o•ûŒüzŠÂƒŠƒXƒg\‘¢‘Ì
 * @param[in,out]   pNode ’Ç‰Á‚·‚éƒm[ƒh
 * @retval          ‚È‚µ
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
 * ‘o•ûŒüzŠÂƒŠƒXƒg‚ÌÅ‰‚Ìƒm[ƒh‚ðŽæ“¾
 * @brief           ‘o•ûŒüzŠÂƒŠƒXƒg‚ÌÅ‰‚Ìƒm[ƒh‚ðŽæ“¾‚·‚é
 * @param[in,out]   pDcll ‘o•ûŒüzŠÂƒŠƒXƒg\‘¢‘Ì
 * @retval          ‚È‚µ
 */
DCLL_NODE volatile *dcll_get_first(DCLL *pDcll)
{
    return pDcll->pPrev;
}

/**
 * @fn
 * ‘o•ûŒüzŠÂƒŠƒXƒg‚É—v‘f‚ð’Ç‰Á
 * @brief           —v‘f‚Ì‘O‚É—v‘f‚ð‘}“ü‚·‚é
 * @param[in,out]   pNode     ‘ÎÛ‚Ìƒm[ƒh
 * @param[in,out]   pEntry    ’Ç‰Á‚·‚éƒGƒ“ƒgƒŠ[
 * @retval          ‚È‚µ
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
 * ‘o•ûŒüzŠÂƒŠƒXƒg‚É—v‘f‚ð’Ç‰Á
 * @brief           —v‘f‚ÌŒã‚ë‚É—v‘f‚ð‘}“ü‚·‚é
 * @param[in,out]   pNode     ‘ÎÛ‚Ìƒm[ƒh
 * @param[in,out]   pEntry    ’Ç‰Á‚·‚éƒGƒ“ƒgƒŠ[
 * @retval          ‚È‚µ
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
 * ‘o•ûŒüzŠÂƒŠƒXƒg‚Ìó‘ÔŽæ“¾
 * @brief           ‘o•ûŒüzŠÂƒŠƒXƒg‚ª‹ó‚©‚Ç‚¤‚©‚ð’²‚×‚é
 * @param[in]       pDcll ‘o•ûŒüzŠÂƒŠƒXƒg\‘¢‘Ì
 * @retval          DCLL_STATE_EMPTY    ‘o•ûŒüƒŠƒXƒg‚Í‹ó
 * @retval          DCLL_STATE_EXIST    ‘o•ûŒüƒŠƒXƒg‚Í‹ó‚Å‚È‚¢
 */
DCLL_STATE dcll_get_state(DCLL_NODE *pDcll)
{
    return ((pDcll->pPrev == pDcll->pNext) ? DCLL_STATE_EMPTY : DCLL_STATE_EXIST);
}

/* End of File */
