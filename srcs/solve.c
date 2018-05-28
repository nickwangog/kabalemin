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

// void        move_ants (t_lem *lem)
// {

// }

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

int minDistance(uint32_t *dist, uint32_t *shortest, int num_room)
{
   // Initialize min value
   int min;
   int i;

   i = 0;
   min = INF;
   int min_index;
  
   while (i < num_room)
   {
     if (shortest[i] == 0 && dist[i] <= min)
     {
        min = dist[i];
        min_index = i;     
     }
     i++;
   }
  
   return min_index;
}
  
// Funtion that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(t_lem *lem, int room_id)
{  
        t_rooms *linkroom;
     int i;
     int v;
     int k;
     i = 0;

     // Initialize all distances as INFINITE and stpSet[] as false
     while(i < lem->num_room)
     {
        lem->dist[room_id][i] = INF;
        lem->shortest[room_id][i] = 0;
        i++;
     }
     // Distance of source vertex from itself is always 0
     lem->dist[room_id][room_id] = 0;
  
     // Find shortest path for all vertices
     i = 0;
     while(i < lem->num_room)
        {

        
       // Pick the minimum distance vertex from the set of vertices not
       // yet processed. u is always equal to src in first iteration.
       int u; 
       
       u = minDistance(lem->dist[room_id], lem->shortest[room_id], lem->num_room);
        find_room(lem->head, u);
       // Mark the picked vertex as processed
       lem->shortest[u] = 1;
        v = 0;
        k = 
       // Update dist value of the adjacent vertices of the picked vertex.
       for (int v = 0; v < V; v++)
        while (v < )
        {
         // Update dist[v] only if is not in sptSet, there is an edge from 
         // u to v, and total weight of path from src to  v through u is 
         // smaller than current value of dist[v]
         if (!lem->shortest[room_id][v] && 
         && lem->dist[room_id][u] != INT_MAX 
         && lem->dist[u] + iflinked(lem, lem->shortest[room_id], lem->dist[room_id]) < lem->dist[v])
         lem->dist[room_id][v] = lem->dist[room_id][u] + 1;
        v++;
        }
        
     }
  
     // print the constructed distance array
     printSolution(dist, V);
}

