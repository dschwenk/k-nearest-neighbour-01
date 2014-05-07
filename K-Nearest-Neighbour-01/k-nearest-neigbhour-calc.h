#include "stdafx.h"
#include <vector>

#include "vector.h"

using namespace std;

// Betrachte K Neigbhours
static const int K = 5;

int calcKNearstNeighbour(Vector* refVektor);
void transferVektor(Vector* SrcVektor, Vector* DestVektor);