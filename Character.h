#pragma once
#include "Root.h"
void Showcharacter(char blockInfo[3][3], int, int);
void DeleteCh(char blockInfo[3][3], int, int);
static char Character[][3][3] =
{
	//기본 스테이지별 모델링
	//1 머리 2 몸통 3~ ㅅ다리 4~ 점프다리 5공격 팔
		  //1스테이지
	   /*
	   ○
	   ┼
	   ∧
	   */

	{
	   {0, 1, 0},
	   {0, 2, 0},
	   {0, 31, 0}},

	   {{0, 1, 0},
	   {0, 2, 0},
	   {0, 31, 0} },
	   /*
	   ○
	   ┼
	   ⅱ
	   */
	   {
	   {0, 1, 0},
	   {0, 2, 0},
	   {0, 101, 0}},
	   {
	   {0, 1, 0},
	   {0, 2, 0},
	   {0, 101, 0}},
	   /*
	   ○
	   ┼
	   ∧
	   */
	  {
	  {0, 1, 0},
	  {0, 2, 0},
	  {0, 31, 0} },
	  {
	  {0, 1, 0},
	  {0, 2, 0},
	  {0, 31, 0} },
	  /*
	  ○
	  ┼
	  ⅱ
	  */
	{
	   {0, 1, 0},
	   {0, 2, 0},
	   {0, 101, 0} },
	   {
	   {0, 1, 0},
	   {0, 2, 0},
	   {0, 101, 0} },

	   /*
	   ○
	   ┼
	   ┴
	   */
   {
	   {0,1, 0},
	   {0,2, 0},
	   {0, 22, 0}},
	   {
	   {0,1, 0},
	   {0,2, 0},
	   {0, 22, 0}},
	   {
	   {0,0, 0},
	   {1,2, 23},
	   {0, 0, 0}},
	   {
	   {0,0, 0},
	   {1,2, 23},
	   {0, 0, 0}},
	   {
	   {0,24, 0},
	   {0,2, 0},
	   {0, 1, 0}},
	   {
	   {0,24, 0},
	   {0,2, 0},
	   {0, 1, 0}},
	   {
	   {0,0, 0},
	   {21,2, 1},
	   {0, 0, 0}},
	   {
	   {0,0, 0},
	   {21,2, 1},
	   {0, 0, 0}},

	   /* ●
		 ┣ο
		 ∧ */
 {
	  {0, 1, 0},
	  {0, 21, 5},
	  {0, 31, 0} },
	  {
	  {0, 1, 0},
	  {0, 21, 5},
	  {0, 31, 0} },
	  /* ●
		┣¤
		∧ */
	{
	{0, 1, 0},
	{0, 21, 51},
	{0, 31, 0} },
	 {
	{0, 1, 0},
	{0, 21, 51},
	{0, 31, 0} },
	/* ●
	   ┣ο
	   ∧ */
   {
	   {0, 1, 0},
	   {0, 21, 5},
	   {0, 31, 0} },
	   {
	   {0, 1, 0},
	   {0, 21, 5},
	   {0, 31, 0} },
	   /* ●
		  ┣¤
		  ∧ */
			 {
			 {0, 1, 0},
			 {0, 21, 51},
			 {0, 31, 0} },
			 {
			 {0, 1, 0},
			 {0, 21, 51},
			 {0, 31, 0} },




			 //1-2스테이지
			 /*  ●╋＜*/
		 {
			 {0,0,0},
			 {1,2,32},
			 {0,0,0}},
			 {
			 {0,0,0},
			 {1,2,32},
			 {0,0,0}},
			 /*  ●╋〓*/
		   {
		   {0,0,0},
		   {1,2,102},
		   {0,0,0} },
		   {
		   {0,0,0},
		   {1,2,102},
		   {0,0,0} },
		   /*  ●╋＜*/
	   {
		   {0,0,0},
		   {1,2,32},
		   {0,0,0} },
			{
		   {0,0,0},
		   {1,2,32},
		   {0,0,0} },
		   /*  ●╋〓*/
		   {
		   {0,0,0},
		   {1,2,102},
		   {0,0,0} },
		   {
		   {0,0,0},
		   {1,2,102},
		   {0,0,0} },

		   /*  ●╋┫*/
	   //2
	  {
	  {0,0, 0},
	  {1,2, 23},
	  {0, 0, 0} },
	{
	  {0,0, 0},
	  {1,2, 23},
	  {0, 0, 0} },


	{
	  {0,24, 0},
	  {0,2, 0},
	  {0, 1, 0} },
	  {
	  {0,24, 0},
	  {0,2, 0},
	  {0, 1, 0} },


	  {
	  {0,0, 0},
	  {21,2, 1},
	  {0, 0, 0} },
	  {
	  {0,0, 0},
	  {21,2, 1},
	  {0, 0, 0} },
	  {
	  {0,1, 0},
	  {0,2, 0},
	  {0, 22, 0} },
	  {
	  {0,1, 0},
	  {0,2, 0},
	  {0, 22, 0} },
	  /*  ο
	   ●┻＜*/

 {
	 {0,5,0},
	 {1,22,32},
	 {0,0,0}},
	  {
	 {0,5,0},
	 {1,22,32},
	 {0,0,0}},
	 /*  ¤
	   ●┻＜*/
 {
 {0,51,0},
 {1,22,32},
 {0,0,0}},
  {
 {0,51,0},
 {1,22,32},
 {0,0,0}},
 /*  ο
   ●┻＜*/
 {
 {0,5,0},
 {1,22,32},
 {0,0,0}},
  {
 {0,5,0},
 {1,22,32},
 {0,0,0}},
 /*  ¤
   ●┻＜*/
 {
 {0,51,0},
 {1,22,32},
 {0,0,0}},
  {
 {0,51,0},
 {1,22,32},
 {0,0,0}},

 //1-3
 /* ∨
	┼
	●*/
 {
	 {0,33,0},
	 {0,2,0},
	 {0,1,0}},
	 {
	  {0,33,0},
	  {0,2,0},
	  {0,1,0}},
	  /* ⅱ
		┼
		●*/
 {
	   {0, 101, 0},
	   {0, 2, 0},
	   {0, 1, 0}},
  {
	   {0, 101, 0},
	   {0, 2, 0},
	   {0, 1, 0}},
	   /* ∨
		 ┼
		 ●*/
 {
	 {0,33,0},
	 {0,2,0},
	 {0,1,0}},
	 {
	  {0,33,0},
	  {0,2,0},
	  {0,1,0}},
	  /* ⅱ
		┼
		●*/
 {
	   {0, 101, 0},
	   {0, 2, 0},
	   {0, 1, 0}},
  {
	   {0, 101, 0},
	   {0, 2, 0},
	   {0, 1, 0}},
	   /* ┳
		 ┼
		 ●*/
  {
	   {0,24, 0},
	   {0,2, 0},
	   {0, 1, 0} },
	   {
	   {0,24, 0},
	   {0,2, 0},
	   {0, 1, 0} },


	   {
	   {0,0, 0},
	   {21,2, 1},
	   {0, 0, 0} },
	   {
	   {0,0, 0},
	   {21,2, 1},
	   {0, 0, 0} },
	   {
	   { 0,1, 0 },
	   { 0,2, 0 },
	   { 0, 22, 0 } },
	   {
	   {0,1, 0},
	   {0,2, 0},
	   {0, 22, 0} },


	   {
	   {0,0, 0},
	   {1,2, 23},
	   {0, 0, 0} },
	{
	   {0,0, 0},
	   {1,2, 23},
	   {0, 0, 0} },


	   /* ∨
	   ο┫
		 ●*/
 {
	 {0,33,0},
	 {5,23,0},
	 {0,1,0} },
 {
	  {0,33,0},
	  {5,23,0},
	  {0,1,0} },
	  /* ∨
	   ¤┫
		●*/
 {
	  {0,33,0},
	  {51,23,0},
	  {0,1,0} },
 {
	  {0,33,0},
	  {51,23,0},
	  {0,1,0} },
	  /* ∨
	   ο┫
		●*/
 {
 {0,33,0},
 {5,23,0},
 {0,1,0} },
 {
	  {0,33,0},
	  {5,23,0},
	  {0,1,0} },
	  /* ∨
	   ¤┫
		●*/
 {
	  {0,33,0},
	  {51,23,0},
	  {0,1,0} },
 {
	  {0,33,0},
	  {51,23,0},
	  {0,1,0} },



	  //1-4
 /*  ＞╋●*/
 {
	 {0, 0, 0},
	 { 34,2,1 },
	 { 0,0,0 } },
 {
	 {0, 0, 0},
	 { 34,2,1 },
	 { 0,0,0 } },
	 /*  〓╋●*/
	 {
	  {0,0,0},
	  {102,2,1},
	  {0,0,0} },
	  {
	  {0,0,0},
	  {102,2,1},
	  {0,0,0} },
	  /*  ＞╋●*/
 {
	 {0, 0, 0},
	 { 34,2,1 },
	 { 0,0,0 } },
 {
	 {0, 0, 0},
	 { 34,2,1 },
	 { 0,0,0 } },
	 /*  〓╋●*/
 {
	   {0,0,0},
	   {102,2,1},
	   {0,0,0} },
 {
	   {0,0,0},
	   {102,2,1},
	   {0,0,0} },
	   /*  ┣╋●*/

	   {
	   {0,0, 0},
	   {21,2, 1},
	   {0, 0, 0} },
	   {
	   {0,0, 0},
	   {21,2, 1},
	   {0, 0, 0} },
	   {
	   {0,1, 0},
	   {0,2, 0},
	   {0, 22, 0} },
	   {
	   {0,1, 0},
	   {0,2, 0},
	   {0, 22, 0} },


	   {
	   {0,0, 0},
	   {1,2, 23},
	   {0, 0, 0} },
	{
	   {0,0, 0},
	   {1,2, 23},
	   {0, 0, 0} },


	{
	   {0,24, 0},
	   {0,2, 0},
	   {0, 1, 0} },
	   {
	   {0,24, 0},
	   {0,2, 0},
	   {0, 1, 0} },

	   /* ＞┳●
		  ο  */
  {
	  {0, 0, 0},
	  { 34,24,1 },
	  { 0,5,0 } },
	   {
	  {0, 0, 0},
	  { 34,24,1 },
	  { 0,5,0 } },
	  /* ＞┳●
		  ¤  */
	   {
	  {0, 0, 0},
	  { 34,24,1 },
	  { 0,51,0 } },
	   {
	  {0, 0, 0},
	  { 34,24,1 },
	  { 0,51,0 } },
	  /* ＞┳●
		  ο  */
  {
	  {0, 0, 0},
	  { 34,24,1 },
	  { 0,5,0 } },
	   {
	  {0, 0, 0},
	  { 34,24,1 },
	  { 0,5,0 } },
	  /* ＞┳●
		  ¤  */
	  {
	 {0, 0, 0},
	 { 34,24,1 },
	 { 0,51,0 } },
	  {
	 {0, 0, 0},
	 { 34,24,1 },
	 { 0,51,0 } },
};