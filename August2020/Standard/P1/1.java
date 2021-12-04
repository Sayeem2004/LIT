import java.util.*;
import java.io.*;

public class Main {
  static class Reader {
    final private int BUF = 1 << 16;
    private DataInputStream d;
    private byte[] bu;
    private int bufP, by;
    public Reader() {
      d = new DataInputStream(System.in);
      bu = new byte[BUF];
      bufP = by = 0;
    }
    public Reader(String fl) throws IOException {
      d = new DataInputStream(new FileInputStream(fl));
      bu = new byte[BUF];
      bufP = by = 0;
    }
    public String readLine() throws IOException {
      byte[] b = new byte[64];
      int ct = 0, c;
      while ((c = read()) != -1) {
        if (c == '\n') break;
          b[ct++] = (byte) c;
		  }
      return new String(b, 0, ct);
    }
    public int nextInt() throws IOException {
      int r = 0;
      byte c = read();
      while (c <= ' ') c = read();
      boolean n = (c == '-');
      if (n) c = read();
      do {
        r = r * 10 + c - '0';
      } while ((c = read()) >= '0' && c <= '9');
      if (n) return -r;
      return r;
    }
    public long nextLong() throws IOException {
      long r = 0;
      byte c = read();
      while (c <= ' ') c = read();
      boolean n = (c == '-');
      if (n) c = read();
      do {
        r = r * 10 + c - '0';
      } while ((c = read()) >= '0' && c <= '9');
      if (n) return -r;
      return r;
    }
    public double nextDouble() throws IOException {
      double r = 0, d = 1;
      byte c = read();
      while (c <= ' ') c = read();
      boolean n = (c == '-');
      if (n) c = read();
      do {
        r = r * 10 + c - '0';
      } while ((c = read()) >= '0' && c <= '9');
      if (c == '.') {
        while ((c = read()) >= '0' && c <= '9') {
          r += (c - '0') / (d *= 10);
        }
      }
      if (n) return -r;
      return r;
    }
    private void fB() throws IOException {
      by = d.read(bu, bufP = 0, BUF);
      if (by == -1) bu[0] = -1;
    }
    private byte read() throws IOException {
      if (bufP == by) fB();
      return bu[bufP++];
    }
    public void close() throws IOException {
      if (d == null) return;
      d.close();
    }
  }
  public static void main(String[] args) throws IOException {
    Reader r = new Reader();
    int N = r.nextInt();
    int M = r.nextInt();
    int L = r.nextInt();
    long time = 0;
    int[][] times = new int[N][2];
    int v = 0;
    int first = r.nextInt();
    times[0][0] = 0;
    times[0][1] = M;
    for (int i = 1; i < N; i++) {
      times[i][0] = r.nextInt() - first;
      times[i][1] = times[i][0] + M;
    }
    int n = 0;
    int[] arr = new int[2 * times[N-1][1]];
    int z = 0;
    for (int i = 0; i < N; i++) {
      for (int j = times[i][0]; j < times[i][1] + n; j++) {
        if (arr[j] < L) {
          arr[j]++;
        } else {
          n++;
        }
        if (i == N - 1) {
          z = times[i][1] + n - 1;
        }
      }
      n = 0;
    }
    for (int i = 0; i < z; i++) {
      if (arr[i] == 0) {
        time++;
      }
    }
    System.out.println(time);
    r.close();
  }
}
