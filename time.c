/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboonpro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 23:21:12 by pboonpro          #+#    #+#             */
/*   Updated: 2023/11/14 23:21:12 by pboonpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

long	now(long past)
{
	return (get_time() - past);
}
