Graph visualiser
================

Compilation
-----------

This program does not need any special libraries and does not have any dependencies. For compilation on Linux systems you can use Make utility (run it in Release directory).
On windows, you can import existing source codes to some C++ IDE (Eclipse, Visual Studio, DevC++, e.t.c.) and you can compile in it.

Using program
-------------

Program is usable via terminal (command line on Windows). It accept one parameter (this parameter is required). This parameter is path to directory where data files are stored. Those data files are required:

* coordinates.txt - contains coordinates of nodes
* all_possible_edges.txt - contains identity matrix of graph
* existinh_edges.txt - contains fix edges (those edges are allways activated)
* optimal_deltas.txt - contains information about edges switched on or off while computation were running

Example of data is in sample_data directory
