function DisjointSet(length) {
    this.parent = new Array(length);

    for(let i = 0; i < length; i++)
        this.parent[i] = i;

    this.find = function find(u) {
        if(u === this.parent[u])
            return u;
        return this.find(this.parent[u]);
    }

    this.merge = function merge(u, v){
        u = this.find(u), v = this.find(v);
        if(u === v) return;
        this.parent[u] = v;
    }


}

let disjointSet = new DisjointSet(n);
