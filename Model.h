#pragma once
#include "Root.h"
void ShowBlock(char blockInfo[5][5], int x1, int y1);
static char Model[][5][5] =
{
	//1~ 색있는 ■ 2▲ 3그냥 ■  4행인 머리 5~몸통 6~다리
   //새 신호등 자가용 버스 행인 하트 빈하트
	//1---------------------------------------------------------------------------
	{
	   {0, 71, 7, 72, 0},

	   {0, 0, 0, 0, 0},

	   {0, 0, 0, 0, 0},

	   {0, 0, 0, 0, 0},

	   {0, 0, 0, 0, 0} },
	{
	   {0, 0, 0, 0, 0},

	   {0, 0, 11, 0, 0},

	   {0, 0, 12, 0, 0},

	   {0, 0, 13, 0, 0},

	   {0, 0, 2, 0, 0} },
   {
		  {0, 0, 0, 0, 0},

		  {0, 0, 0, 0, 0},

		  {0, 1, 1, 1, 0},

		  {1, 1, 1, 1, 1},

		  {0, 3, 0, 3, 0} },
   {
			 {0, 0, 0, 0, 0},

			 {0, 0, 0, 0, 0},

			 {1, 1, 1, 1, 1},

			 {1, 1, 1, 1, 1},

			 {0, 3, 0, 3, 0} },
   {
				{0, 0, 0, 0, 0},

				{0, 0, 0, 0, 0},

				{0, 0, 4, 0, 0},

				{0, 0, 51, 0, 0},

				{0, 0, 61, 0, 0} },
   {
				   {0, 0, 0, 0, 0},

				   { 0, 0, 0, 0, 0 },

				   { 0, 81, 0, 81, 0 },

					{ 0, 11, 11, 11, 0 },

					{ 0, 0, 82, 0, 0 } },//5-1
					{
				{0, 0, 0, 0, 0},

				{0, 0, 0, 0, 0},

				{0, 0, 41, 0, 0},

				{0, 0, 41, 0, 0},

				{0, 0, 41, 0, 0} },
					{
				   {0, 0, 0, 0, 0},

				   { 0, 0, 0, 0, 0 },

				   { 0, 85, 0, 85, 0 },

					{ 0, 14, 14, 14, 0 },

					{ 0, 0, 86, 0, 0 } },//5-11
				//2-------------------------------------------------------------
				{
					{0, 0, 0, 0, 0},

					{73, 0, 0, 0, 0},

					{7, 0, 0, 0, 0},

					{74, 0, 0, 0, 0},

					{0, 0, 0, 0, 0} },
				 {
					{0, 0, 0, 0, 0},

					{0, 0, 0, 0, 0},

					{0, 11, 12, 13, 21},

					{0, 0, 0, 0, 0},

					{0, 0, 0, 0, 0} },//2
				 {
						{0, 0, 0, 1, 0},

						{0, 0, 1, 1, 3},

						{0, 0, 1, 1, 0},

						{0, 0, 1, 1, 3},

						{0, 0, 0, 1, 0} },//2
				 {
						   {0, 0, 1, 1, 0},

						   {0, 0, 1, 1, 3},

						   {0, 0, 1, 1, 0},

						   {0, 0, 1, 1, 3},

						   {0, 0, 1, 1, 0} },//2
				 {
							   {0, 0, 0, 0, 0},

							   {0, 0, 0, 0, 0},

							   {0, 0, 4, 52, 62},

							   {0, 0, 0, 0, 0},

							   {0, 0, 0, 0, 0} },//2

				 {
									{0, 0, 0, 0, 0},

									{0, 0, 83, 11, 0},

									{0, 0, 0, 11, 84},

									{0, 0, 83, 11, 0},

									{0, 0, 0, 0, 0} },//5-2
									{
				{0, 0, 0, 0, 0},

				{0, 0, 0, 0, 0},

				{0, 0, 41, 41, 41},

				{0, 0, 0, 0, 0},

				{0, 0, 0, 0, 0} },
									 {
									{0, 0, 0, 0, 0},

									{0, 0, 87, 14, 0},

									{0, 0, 0, 14, 88},

									{0, 0, 87, 14, 0},

									{0, 0, 0, 0, 0} },//5-21
				//3--------------------------------------------------------
				 {
					{0, 0, 0, 0, 0},

					{0, 0, 0, 0, 0},

					{0, 0, 0, 0, 0},

					{0, 0, 0, 0, 0},

					{0, 71, 7, 72, 0} },

				 {
					{0, 0, 22, 0, 0},

					{0, 0, 13, 0, 0},

					{0, 0, 12, 0, 0},

					{0, 0, 11, 0, 0},

					{0, 0, 0, 0, 0} },//3
				 {
						{0, 3, 0, 3, 0},

						{1, 1, 1, 1, 1},

						{0, 1, 1, 1, 0},

						{0, 0, 0, 0, 0},

						{0, 0, 0, 0, 0} },//3
				 {
						   {0, 3, 0, 3, 0},

						   {1, 1, 1, 1, 1},

						   {1, 1, 1, 1, 1},

						   {0, 0, 0, 0, 0},

						   {0, 0, 0, 0, 0} },//3
				 {
							   {0, 0, 63, 0, 0},

							   {0, 0, 53, 0, 0},

							   {0, 0, 4, 0, 0},

							   {0, 0, 0, 0, 0},

							   {0, 0, 0, 0, 0} },//3

				 {
									{0, 0, 81, 0, 0},

									{0, 11, 11, 11, 0},

									{0, 82, 0, 82, 0},

									{0, 0, 0, 0, 0},

									{0, 0, 0, 0, 0} },//5-3
									{
				{0, 0, 41, 0, 0},

				{0, 0, 41, 0, 0},

				{0, 0, 41, 0, 0},

				{0, 0, 0, 0, 0},

				{0, 0, 0, 0, 0} },
									 {
									{0, 0, 85, 0, 0},

									{0, 14, 14, 14, 0},

									{0, 86, 0, 86, 0},

									{0, 0, 0, 0, 0},

									{0, 0, 0, 0, 0} },//5-31
				//4--------------------------------------------------
				 {
					{0, 0, 0, 0, 0},

					{0, 0, 0, 0, 73},

					{0, 0, 0, 0, 7},

					{0, 0, 0, 0, 74},

					{0, 0, 0, 0, 0} },
				 {
					{0, 0, 0, 0, 0},

					{0, 0, 0, 0, 0},

					{23, 13, 12, 11, 0},

					{0, 0, 0, 0, 0},

					{0, 0, 0, 0, 0} },//4
				 {
						{0, 1, 0, 0, 0},

						{3, 1, 1, 0, 0},

						{0, 1, 1, 0, 0},

						{3, 1, 1, 0, 0},

						{0, 1, 0, 0, 0} },//4
				 {
						   {0, 1, 1, 0, 0},

						   {3, 1, 1, 0, 0},

						   {0, 1, 1, 0, 0},

						   {3, 1, 1, 0, 0},

						   {0, 1, 1, 0, 0} },//4
				 {
							   {0, 0, 0, 0, 0},

							   {0, 0, 0, 0, 0},

							   {64, 54, 4, 0, 0},

							   {0, 0, 0, 0, 0},

							   {0, 0, 0, 0, 0} },//4

				 {
							   {0, 0, 0, 0, 0},

							   {0, 11, 84, 0, 0},

							   {83, 11, 0, 0, 0},

							   {0, 11, 84, 0, 0},

							   {0, 0, 0, 0, 0} },//5-4



 {
				{0, 0, 0, 0, 0},

				{0, 0, 0, 0, 0},

				{41, 41, 41, 0, 0},

				{0, 0, 0, 0, 0},

				{0, 0, 0, 0, 0} },
						{
						   {0, 0, 0, 0, 0},

						   { 0, 14, 88, 0, 0 },

						   { 87, 14, 0, 0, 0 },

						   { 0, 14, 88, 0, 0 },

						   { 0, 0, 0, 0, 0 } },//5-5

 //----------------------------------------------------------------------------------------------------------------------------------
				{
				   {15, 16, 15, 16, 15},

				   { 16, 15, 16, 15, 16 },

				   { 96, 0, 0, 0, 96 },

				   { 96, 0, 0, 0, 96},

				   { 2, 0, 0, 0, 2 } },
									{
									   {15, 16, 95, 95, 21},

									   { 16, 15, 0, 0, 0 },

									   { 15, 16, 0, 0, 0 },

									   { 16, 15, 0, 0, 0 },

									   { 15, 16, 95, 95, 21 } },

									{
									   {22, 0, 0, 0, 22},

									   { 96, 0,0, 0, 96 },

									   { 96, 0, 0, 0, 96 },

									   { 16, 15, 16, 15, 16 },

									   { 15, 16, 15, 16, 15 } },
									{
									   {23, 95, 95, 16, 15},

									   { 0, 0, 0, 15, 16 },

									   { 0, 0, 0, 16, 15},

									   { 0, 0, 0, 15, 16},

									   { 23, 95, 95, 16, 15 } }



};