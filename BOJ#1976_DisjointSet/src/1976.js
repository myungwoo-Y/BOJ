const readline = require('readline');
const fs = require('fs');
const path = require("path");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

// const rl = readline.createInterface({
//     input: fs.createReadStream(path.resolve(__dirname, "./in.txt")),
// });

const ascending = (a, b) => a - b;
const desending = (a, b) => b - a;
const getListByLine = (arr) => arr.split(' ').map(e => parseInt(e));

const getHead = list => list[0];
const getTail = list => list[list.length - 1];
const createOneValueList = value => n => new Array(n).fill(value);

let input = [];

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

rl.on('line', (line) => {
    input.push(line)
}).on('close', () => {

    let n = parseInt(input.shift());
    let m = parseInt(input.shift());

    let disjointSet = new DisjointSet(n);
    let graph = [];
    for(let i = 0; i < n; i++)
        graph.push(getListByLine(input.shift()));

    for(let i = 0; i < n; i++){
        for(let j = 0; j < n; j++){
            if(graph[i][j] === 1)
                disjointSet.merge(i, j);
        }
    }

    let visitList = getListByLine(input.shift()).map(e => e-1);

    let connected = "YES";
    let trueParent = disjointSet.find(visitList[0]);
    for(let i = 0; i < visitList.length; i++){
        let curParent = disjointSet.find(visitList[i]);
        if(trueParent !== curParent){
            connected = "NO";
            break;
        }
    }
    console.log(connected);
    process.exit();
});