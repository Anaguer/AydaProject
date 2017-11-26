# include <iostream>

# include <tpl_graph.H>

# include <Prim.H>

# include <tpl_graph_utils.H>

using namespace std;

// Alias para el tipo de nodo y arcos.
using Node = Graph_Node<string>;

using Arc = Graph_Arc<float>;

// Alias para el tipo de grafo. Por omisión el grafo trabaja con arcos vacíos.
using GT = List_Graph<Node, Arc>;

void print_graph(GT & g)
{
  // Imprime la cantidad total de arcos del grafo
  cout << g.get_num_arcs() << " arcs\n";

  // Itera sobre todos los arcos del grafo.
  for (GT::Arc_Iterator it(g); it.has_curr(); it.next())
    {
      auto a = it.get_curr();

      /* Cuando se trata de digrafos, src_node es el nodo del cual sale el arco
	 y tgt es el que está en la punta de la flecha, es decir, a donde llega
	 el arco. */
      auto p = g.get_src_node(a);
      auto q = g.get_tgt_node(a);

      cout << p->get_info() << " -- " << q->get_info() << endl;
    }
}

int main(int argc, char const *argv[])
{
	GT Graph, Tree;

	auto Distribucion = Graph.insert_node("Distribucion");
	auto ElCampito1 = Graph.insert_node("ElCampito1");
	auto ElCampito2 = Graph.insert_node("ElCampito2");
	auto ElCampito3 = Graph.insert_node("ElCampito3");
	auto ElCampito4 = Graph.insert_node("ElCampito4");
	auto ElCampito5 = Graph.insert_node("ElCampito5");
	auto ElCampito6 = Graph.insert_node("ElCampito6");
	auto ElCampito7 = Graph.insert_node("ElCampito7");
	auto ElLlanito1 = Graph.insert_node("ElLlanito1");
	auto Carupano1 = Graph.insert_node("Carupano1");

	Graph.insert_arc(Distribucion, ElCampito1, 120.00);
	Graph.insert_arc(Distribucion, ElLlanito1, 123.2);
	Graph.insert_arc(ElCampito1,ElCampito2, 125.5);
	Graph.insert_arc(ElCampito2,ElCampito3, 120.2);
	Graph.insert_arc(ElCampito3,ElCampito4, 121.3);
	Graph.insert_arc(ElCampito4,ElCampito5, 124.2);
	Graph.insert_arc(ElCampito5,ElCampito6, 123.0);
	Graph.insert_arc(ElCampito6,ElCampito7, 122.31);
	Graph.insert_arc(ElLlanito1,Carupano1, 120.2);

	print_graph(Graph);	
	Aleph::Prim_Min_Spanning_Tree< GT > a;
	a(Graph, Distribucion,Tree);
	print_graph(Tree);


	return 0;
}