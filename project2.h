#define MAXNODES 29

// Structure for element in array
struct Element {
	int i;
	int v;
};

struct node {
    char id[10];
    char name[100];
};

struct arc {
    int adj;
};

struct graph {
    struct node nodes[MAXNODES];
    struct arc arcs[MAXNODES][MAXNODES];
};

// join function to create edge from one node to another
void join(struct arc arcs[][MAXNODES], int from, int to) {
    arcs[from][to].adj = true;
}

int visited[MAXNODES];
int clock = 0;
struct Element pre[MAXNODES];
struct Element post[MAXNODES];

void previsit(struct graph g, int v) {
    pre[v].i = v;
    pre[v].v = ++clock;
}
void postvisit(struct graph g, int v) {
    post[v].i = v;
    post[v].v = ++clock;
}

void explore(struct graph g, int v) {
    visited[v] = true;
    previsit(g, v);
    for (int i = 0; i < MAXNODES; i++) {
        if (g.arcs[v][i].adj == true) {
            if (!visited[i]) {
                explore(g, i);
            }
        }
    }
    postvisit(g, v);
}
void dfs(struct graph g) {
    for (int i = 0; i < MAXNODES; i++) {
        visited[i] = false;
    }
    for (int i = 0; i < MAXNODES; i++) {
        if (!visited[i]) {
            explore(g, i);
        }
    }
}

// 1. MERGE SORT IN DESCENDING ORDER
// Merge function to combine arrays
void merge(struct Element L[], struct Element R[], int lenL, int lenR, struct Element merged[]) {
	int combLen = lenL + lenR;
	int i = 0, j = 0;
	for (int k = 0; k < combLen; k++) {
		if (j > (lenR-1) || (i <= (lenL-1) && (L[i].v >= R[j].v))) {
			merged[k] = L[i];
			i++;
		}
		else {
			merged[k] = R[j];
			j++;
		}
	}
}

// Merge Sort function to recursively divide array into 2 arrays with haft size
struct Element* mergeSort(struct Element array[], int len) {

	if (len == 1) {
		return array;
	}
	
	else {

		struct Element* L = (struct Element*) malloc((len/2)*sizeof(struct Element));
		struct Element* R = (struct Element*) malloc((len - len/2)*sizeof(struct Element));

		for (int i = 0; i < len/2; i++) {
			L[i] = array[i];
		}
		for (int i = 0; i < len-len/2; i++) {
			R[i] = array[len/2 + i];
		}
		

		struct Element* LS = mergeSort(L, len/2);
		struct Element* RS = mergeSort(R, len-len/2);
		struct Element* merged = (struct Element*) malloc(len * sizeof(struct Element));
		merge(LS, RS, len/2, len-len/2, merged);

		free(L);
		free(R);
		return merged;
	}
}