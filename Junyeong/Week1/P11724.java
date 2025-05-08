import java.io.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

// 11724 연결요소의 개수
public class P11724 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    static int N,M,count;
    static boolean []visited;
    static int [][]CC;

    public static void main(String[] args) throws IOException {
        st=new StringTokenizer(br.readLine());
        N=Integer.parseInt(st.nextToken());
        M=Integer.parseInt(st.nextToken());
        visited = new boolean[N+1];
        CC = new int[N+1][N+1];

        for (int i = 1; i <= M; i++) {
            st=new StringTokenizer(br.readLine());
            int u=Integer.parseInt(st.nextToken());
            int v=Integer.parseInt(st.nextToken());
            CC[u][v]=1;
            CC[v][u]=1;
        }

        for(int i=1;i<=N;i++){
            if(!visited[i]) {
                solve(i);
                count++;
            }
        }

        bw.write(count+"\n");
        bw.flush();

    }

    public static void solve(int start) throws IOException {
        Queue<Integer> q = new LinkedList<>();
        q.add(start);
        visited[start]=true;
        while(!q.isEmpty()) {
            start=q.poll();
            for(int i=1;i<=N;i++){
                if(CC[start][i]==1&&!visited[i]){
                    visited[i]=true;
                    q.add(i);
                }
            }
        }
    }
}