
package question;

public class ZigZagString {
    public static void main(final String[] argv) {
        final ZigZagString zigzag = new ZigZagString();
        System.out.println(zigzag.transform("PAYPALISHIRING"));
    }

    int M = 3;
    int N = 4;

    String transform(final String input) {
        if (input.length() <= M) {
            return input;
        } else {
            final int n = input.length() / N;
            final int nRes = input.length() - n * N;
            String line1 = "";
            String line2 = "";
            String line3 = "";
            for (int i = 0; i < n; i++) {
                line1 += input.charAt(i * N);
                line2 += "" + input.charAt(i * N + 1) + input.charAt(i * N + 3);
                line3 += input.charAt(i * N + 2);
            }
            switch (nRes) {
                case 0:
                    break;
                case 1:
                    line1 += input.charAt(n * N);
                    break;
                case 2:
                    line1 += input.charAt(n * N);
                    line2 += input.charAt(n * N + 1);
                    break;
                case 3:
                    line1 += "" + input.charAt(n * N) + input.charAt(n * N + 2);
                    line2 += input.charAt(n * N + 1);
                    break;
                case 4:
                    line1 += "" + input.charAt(n * N) + input.charAt(n * N + 2);
                    line2 += input.charAt(n * N + 1);
                    line3 += input.charAt(n * N + 2);
                    break;
            }
            return line1 + line2 + line3;
        }
    }
}
