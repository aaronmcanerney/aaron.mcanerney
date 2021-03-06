//--------------------------------------------------------------------
//
//  Laboratory 12                                      WeightedGraph.h
//
//  Class declaration for the adjacency matrix implementation of
//  the Weighted Graph ADT
//
//--------------------------------------------------------------------

#ifndef WEIGHTEDGRAPH_H
#define WEIGHTEDGRAPH_H

#include <stdexcept>
#include <iostream>
#include <climits>    // For INT_MAX
#include <string>     // Used for labels

using namespace std;

class WeightedGraph
{
  public:
    static const int 
	MAX_GRAPH_SIZE = 10,         // Default number of vertices
	INFINITE_EDGE_WT = INT_MAX;  // "Weight" of a missing edge

    class Vertex
    {
      public:
	void setLabel( const string& newLabel ) { label=newLabel; }
	string getLabel( ) const { return label; }
	void setColor(char newColor) { color = newColor; }
	char getColor() const { return color; }
    
      private:
        string label;   // Vertex label
        char color;
    };

    //--------------------------------------------------------------------

    // Constructors
    WeightedGraph ( int maxNumber = MAX_GRAPH_SIZE );
    WeightedGraph ( const WeightedGraph& other );
    // Overloaded assignment operator
    WeightedGraph& operator= ( const WeightedGraph& other );

    // Destructor
    ~WeightedGraph ();

    // Graph manipulation operations
    void insertVertex ( const Vertex& newVertex )            // Insert vertex
        throw ( logic_error );
    void insertEdge ( const string& v1, const string& v2, int wt )    // Insert edge
        throw ( logic_error );
    bool retrieveVertex ( const string& v, Vertex& vData ) const;
                                                      // Get vertex
    bool getEdgeWeight ( const string& v1, const string& v2, int& wt ) const
        throw ( logic_error );                        // Get edge wt.
    void removeVertex ( const string& v )                     // Remove vertex
        throw ( logic_error );
    void removeEdge ( const string& v1, const string& v2 )            // Remove edge
        throw ( logic_error );
    void clear ();                                    // Clear graph

    // Graph status operations
    bool isEmpty () const;                            // Graph is empty
    bool isFull () const;                             // Graph is full

    // Output the graph structure -- used in testing/debugging
    void showStructure () const;

    // Programming exercise operations
    void showShortestPaths ();
    bool hasProperColoring() const;
    bool areAllEven () const;
    
    inline bool inBound(int index) const{
      if(index >= 0 && index < size){
        return true;
      }
      return false;
    }
    
    inline bool inBoundV(int index) const {
      if(index >= 0 && index < size){
        return true;
      }
      return false;
    }

    inline int conv1D(int row, int col) const {
        return (maxSize * row) + col;
    }

    inline void collapseCol(int start){
        cout << "IN collapse43" << endl;
        for(int i = 0; i < size; i++){
        cout << "index " << start <<" to " << start +1 <<endl;
            cout << "setting " << adjMatrix[start] << " to " << adjMatrix[start+1] << endl;
            adjMatrix[start] = adjMatrix[start+1];
            start+=size;
        }
    }

    inline void collapseRow(int start){
        for(int i = 0; i < size; i++){
            adjMatrix[start] = adjMatrix[start+size];
            start++;
        }
    }
    
  private:
    
    // Facilitator functions
    int getIndex ( const string& v ) const;          // Converts vertex label to an
                                             //   adjacency matrix index
    void fillMatrix();
    int getEdge ( int row, int col ) const;          // Get edge weight using
                                               //   adjacency matrix indices
    void setEdge ( int row, int col, int wt);  // Set edge weight using
                                               //   adjacency matrix indices
    // Data members
    int maxSize,          // Maximum number of vertices in the graph
        size;             // Actual number of vertices in the graph
    Vertex *vertexList;   // Vertex list
    int *adjMatrix;       // Adjacency matrix

};

#endif		// #ifndef WEIGHTEDGRAPH_H
