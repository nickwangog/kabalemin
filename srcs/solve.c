/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 16:58:12 by nwang             #+#    #+#             */
/*   Updated: 2018/05/26 16:58:18 by nwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void        dijkstra(t_lem *lem)
{
        // create a shortest path set (array), keeps 
        // track of vertices whose minimum distance from
        // start is calculated, empty to begin with.
        
        // assign all distance values as infinity, start vertex as zero

        // pick next vertex with minimun distance value, include it to the
        // shortest path set, update adjacent vertices of last picked vertex
        // , recalculate distances and weights
}