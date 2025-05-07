import java.io.*;
import java.util.StringTokenizer;

//2630 색종이 만들기

public class Problem1 {
    static int blue,white,same,N;
    static int[][] paper;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    public static void main(String[] args) throws IOException {
        N=Integer.parseInt(br.readLine());
        paper=new int[N][N];
        for(int i=0;i<N;i++){
            st=new StringTokenizer(br.readLine());
            for(int j=0;j<N;j++){
                paper[i][j]=Integer.parseInt(st.nextToken());
            }
        }

        divide(0,0, N);
        bw.write(white+"\n"+blue);
        bw.flush();
    }

    static void divide(int start_x,int start_y,int now_N) {
        if(now_N==1){
            if(paper[start_x][start_y]==1){
                blue++;
            }
            else{
                white++;
            }
            return;
        }
        else{
            boolean cont=false;

            same=paper[start_x][start_y];

            for(int i=start_x;i<start_x+now_N;i++){
                for(int j=start_y;j<start_y+now_N;j++){
                    if(paper[i][j]!=same){
                        cont=true;
                        break;
                    }
                }
                if(cont){
                    break;
                }
            }

            if(cont){
                divide(start_x,start_y,now_N/2);
                divide(start_x+now_N/2,start_y,now_N/2);
                divide(start_x,start_y+now_N/2,now_N/2);
                divide(start_x+now_N/2,start_y+now_N/2,now_N/2);
            }else{
                if(same==1){
                    blue++;
                }
                else{
                    white++;
                }
                return;
            }
        }
    }
}