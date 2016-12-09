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
 * @param[in,out]   pstDcll ‘o•ûŒüzŠÂƒŠƒXƒg\‘¢‘Ì
 * @retval          ‚È‚µ
 */
void dcll_init(S_DCLL *pstDcll)
{
    pstDcll->pstPrev = pstDcll;
    pstDcll->pstNext = pstDcll;
}

/**
 * @fn
 * ‘o•ûŒüzŠÂƒŠƒXƒg‚ÌI—¹
 * @brief           ‘o•ûŒüzŠÂƒŠƒXƒg‚Ì—v‘f‚ð”jŠü‚µAI—¹‚·‚é
 * @param[in,out]   pstDcll ‘o•ûŒüzŠÂƒŠƒXƒg\‘¢‘Ì
 * @retval          ‚È‚µ
 */
void dcll_term(S_DCLL *pstDcll)
{
    dcll_init(pstDcll);
}

/**
 * @fn
 * ‘o•ûŒüzŠÂƒŠƒXƒg‚Éƒm[ƒh‚ð’Ç‰Á
 * @brief           ‘o•ûŒüzŠÂƒŠƒXƒg‚Ì––”ö‚Éƒm[ƒh‚ð’Ç‰Á‚·‚é
 * @param[in,out]   pstDcll ‘o•ûŒüzŠÂƒŠƒXƒg\‘¢‘Ì
 * @param[in,out]   pstNode ’Ç‰Á‚·‚éƒm[ƒh
 * @retval          ‚È‚µ
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
 * ‘o•ûŒüzŠÂƒŠƒXƒg‚Ìƒm[ƒh‚ðíœ
 * @brief           ‘o•ûŒüzŠÂƒŠƒXƒg‚Ìƒm[ƒh‚ðíœ‚·‚é
 * @param[in,out]   pstDcll ‘o•ûŒüzŠÂƒŠƒXƒg\‘¢‘Ì
 * @param[in,out]   pstNode ’Ç‰Á‚·‚éƒm[ƒh
 * @retval          ‚È‚µ
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
 * ‘o•ûŒüzŠÂƒŠƒXƒg‚ÌÅ‰‚Ìƒm[ƒh‚ðŽæ“¾
 * @brief           ‘o•ûŒüzŠÂƒŠƒXƒg‚ÌÅ‰‚Ìƒm[ƒh‚ðŽæ“¾‚·‚é
 * @param[in,out]   pstDcll ‘o•ûŒüzŠÂƒŠƒXƒg\‘¢‘Ì
 * @retval          ‚È‚µ
 */
S_DCLL_NODE volatile *dcll_get_first(S_DCLL *pstDcll)
{
    return pstDcll->pstPrev;
}

/**
 * @fn
 * ‘o•ûŒüzŠÂƒŠƒXƒg‚É—v‘f‚ð’Ç‰Á
 * @brief           —v‘f‚Ì‘O‚É—v‘f‚ð‘}“ü‚·‚é
 * @param[in,out]   pstNode     ‘ÎÛ‚Ìƒm[ƒh
 * @param[in,out]   pstEntry    ’Ç‰Á‚·‚éƒGƒ“ƒgƒŠ[
 * @retval          ‚È‚µ
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
 * ‘o•ûŒüzŠÂƒŠƒXƒg‚É—v‘f‚ð’Ç‰Á
 * @brief           —v‘f‚ÌŒã‚ë‚É—v‘f‚ð‘}“ü‚·‚é
 * @param[in,out]   pstNode     ‘ÎÛ‚Ìƒm[ƒh
 * @param[in,out]   pstEntry    ’Ç‰Á‚·‚éƒGƒ“ƒgƒŠ[
 * @retval          ‚È‚µ
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
 * ‘o•ûŒüzŠÂƒŠƒXƒg‚Ìó‘ÔŽæ“¾
 * @brief           ‘o•ûŒüzŠÂƒŠƒXƒg‚ª‹ó‚©‚Ç‚¤‚©‚ð’²‚×‚é
 * @param[in]       pstDcll ‘o•ûŒüzŠÂƒŠƒXƒg\‘¢‘Ì
 * @retval          TRUE    ‘o•ûŒüƒŠƒXƒg‚Í‹ó
 */
E_DCLL_STATE dcll_get_stat(S_DCLL *pstDcll)
{
    return ((pstDcll->pstPrev == pstDcll->pstNext) ? E_DCLL_STATE_EMPTY : E_DCLL_STATE_EXIST);
}

/* End of File */
