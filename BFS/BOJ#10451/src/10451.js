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

const idx = (_idx) => {
    return idx-1;
}

let input = [];
let n;
let graph;
let arr = [];

const dfs = (v, visited) => {
    if(visited[v])
        return;
    visited[v] = true;
    for(let i = 1; i <= n; i++){
        if(!visited[i] && graph[i][v]){
            dfs(i, visited);
        }
    }
}

rl.on('line', (line) => {
    input.push(line);
}).on('close', () => {
    let testCase = 0;
    testCase = parseInt(input.shift());

    for(let repeat = 0; repeat < testCase; repeat++){
        n = parseInt(input.shift());
        arr = input.shift().split(' ').map(e => parseInt(e));
        graph = [];
        for(let i = 0; i <= n; i++){
            graph.push(new Array(n+1).fill(false));
        }

        arr.forEach((e,i) => {
            graph[i+1][e] = true;
            graph[e][i+1] = true;
        })

        let visited = new Array(n+1).fill(false);

        let ans = 0;
        for(let i = 1; i <= n; i++){
            if(!visited[i]){
                ans++;
                dfs(i, visited);
            }
        }
        console.log(ans);
    }
    process.exit();
});