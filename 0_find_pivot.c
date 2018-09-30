/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 21:42:52 by qpeng             #+#    #+#             */
/*   Updated: 2018/09/30 01:18:33 by qpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
	Assignment name  : find_pivot
	Expected files   : find_pivot.c
	Allowed functions: 
	--------------------------------------------------------------------------------
	ALERT: OPTIMIZED SOLUTION REQUIRED.
	Given an array of integers and its size passed as parameters,
	create a function able to return the pivot index of this array.
	The pivot index is the index where the sum of the numbers on the left
	is equal to the sum of the numbers on the right.
	The function must be declared as follows:
	    int find_pivot(int *arr, int n);
	If there is no pivot present, return -1.
	Considerations:
	- Be careful: the naive solution won't work on our big input, you have to
	find an optimized solution which will run in O(n) time (where n is the
	length of the array). 
	- The array will always have a length bigger than 1.
	- You don't have to take care of overflow or underflow of sums,
	it will stay in an range of an int.
	- The bigger test we will do is on an array of 1.000.000 elements.
	It should run in less than 2 seconds.
	 
	Example 1:
	    arr = [ 1, 2, 3, 4, 0, 6 ] , n = 6
	In this case, your function should return 3.
	Because at index 3, the sum of the elements on the left is equals
	to the sum of the elements on the right:
	    = 6        = 6
	  _______     ____
	[ 1, 2, 3, 4, 0, 6 ]
	           ^
	           |
	     with pivot = 3
	Example 2: 
	arr = [ -5, 10, 2, 5 ] , n = 4
	In this case, your function should return 2.
	Example 3:
	arr = [ 1, 100, 0, 0, 1 ] , n = 5
	In this case, your function should return 1.
	Example 4:
	arr = [ 7, 9, 8 ] , n = 3
	In this case, your function should return -1.
	Example 5:
	arr = [ 1 , 2 ] , n = 2
	In this case, your function should return -1.
*/
/*== O(n) ==*/


 int find_pivot(int *arr, int n)
{
	int			i = 0;
	long long sum = 0, cur;

	while (i < n)
	{
		sum += arr[i];
		i++;
	}
	cur = arr[0];
	i = 1;
	while (i < n)
	{
		cur += arr[i];
		sum -= arr[i - 1];
		if (cur == sum)
			return i;
		i++;
	}
	return (-1);
}

/*
#include <stdio.h>
int	main(void)
{
	int arr[] = {1, 100, 0, 0, 1 };
	printf("%d\n",  find_pivot(arr, 5));

	int arr2[] = {1, 2, 3, 4, 0, 6 };
	printf("%d\n",  find_pivot(arr2, 6));
	return (0);
}
*/