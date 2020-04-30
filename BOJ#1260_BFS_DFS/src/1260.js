const readline = require('readline');
const fs = require('fs');
const path = require("path");

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

// const rl = readline.createInterface({
//     input: fs.createReadStream(path.resolve(__dirname, "in.txt")),
// });

let input = [];
let graph = [];

const bfs = () => {
    let visited = Array.from({length: n+1}, () => false);
    let q = [];
    let ret = '';
    visited[start] = true;
    q.push(start);
    ret += start + ' ';
    while(q.length != 0){
        let v = q.shift();
        for(let i = 1; i <= n; i++){
            if(graph[v][i] && !visited[i]){
                visited[i] = true;
                q.push(i);
                ret += i + ' ';
            }
        }
    }
    return ret;
}

const dfs = (v, visited) => {
    if(visited[v])
        return '';
    let ret = v + ' ';
    visited[v] = true;
    for(let i = 1; i <= n; i++) {
        if (graph[v][i] && !visited[i]) {
            ret += dfs(i, visited);
        }
    }
    return ret;
}

let n,m,start;
rl.on('line', (line) => {
    input.push(line.trim());
}).on('close', () => {
    [n, m, start] = input.shift().split(' ').map(e => parseInt(e));

    for(let i = 0; i <= n; i++){
        graph.push(Array.from({length: n+1}, (e, i) => false));
    }

    for(let i = 0; i < m; i++){
        let [a, b] = input.shift().split(' ').map(e => parseInt(e));
        graph[a][b] = true;
        graph[b][a] = true;
    }
    console.log(dfs(start, Array.from({length: n+1}, ()=>false)))
    console.log(bfs());
    process.exit();
});