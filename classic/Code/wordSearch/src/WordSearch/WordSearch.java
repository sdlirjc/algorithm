
package WordSearch;

import java.util.ArrayList;
import java.util.Stack;

public class WordSearch {
    class Pair {
        int k;
        Pair parent;
        int x;
        int y;

        Pair(final int x, final int y, final int k, final Pair parent) {
            this.x = x;
            this.y = y;
            this.k = k;
            this.parent = parent;
        }
    }

    public static void main(final String[] argv) {
        final WordSearch search = new WordSearch();
        final char[][] input = {
                {
                        'a', 'a'
            }
        };
        final char[][] input1 = {
                {
                        'A', 'B', 'C', 'E'
                }, {
                        'S', 'F', 'C', 'S'
                }, {
                        'A', 'D', 'E', 'E'
                }
        };
        final String word = "aaa";
        final String word1 = "ABCB";
        System.out.println(search.exist(input, word));
    }

    public boolean exist(final char[][] board, final String word) {
        // Start typing your Java solution below
        // DO NOT write main() function
        final int m = board.length;
        final int n = board[0].length;
        final ArrayList<Pair> pairs = new ArrayList<Pair>();
        if (m * n < word.length()) {
            return false;
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word.charAt(0)) {
                    pairs.add(new Pair(i, j, 0, null));
                }
            }
        }
        boolean retVal = false;
        for (int i = 0; i < pairs.size(); i++) {
            final Stack<Pair> stacks = new Stack<Pair>();
            stacks.push(pairs.get(i));
            int j = 0;
            while (!stacks.empty()) {
                final Pair pair = stacks.pop();
                j = pair.k + 1;
                if (j < word.length()) {
                    if (board[(pair.x + 1) % m][pair.y % n] == word.charAt(j)) {
                        boolean isRepeated = false;
                        Pair tmp = pair.parent;
                        while (tmp != null) {
                            if ((pair.x + 1) % m == tmp.x && pair.y % n == tmp.y) {
                                isRepeated = true;
                                break;
                            } else {
                                tmp = tmp.parent;
                            }
                        }
                        if (!isRepeated) {
                            stacks.push(new Pair((pair.x + 1) % m, pair.y % n, j, pair));
                        }
                    }
                    if (board[(pair.x + m - 1) % m][pair.y % n] == word.charAt(j)) {
                        boolean isRepeated = false;
                        Pair tmp = pair.parent;
                        while (tmp != null) {
                            if ((pair.x + m - 1) % m == tmp.x && pair.y % n == tmp.y) {
                                isRepeated = true;
                                break;
                            } else {
                                tmp = tmp.parent;
                            }
                        }
                        if (!isRepeated) {
                            stacks.push(new Pair((pair.x + m - 1) % m, pair.y % n, j, pair));
                        }
                    }
                    if (board[(pair.x) % m][(pair.y + 1) % n] == word.charAt(j)) {
                        boolean isRepeated = false;
                        Pair tmp = pair.parent;
                        while (tmp != null) {
                            if ((pair.x) % m == tmp.x && (pair.y + 1) % n == tmp.y) {
                                isRepeated = true;
                                break;
                            } else {
                                tmp = tmp.parent;
                            }
                        }
                        if (!isRepeated) {
                            stacks.push(new Pair((pair.x) % m, (pair.y + 1) % n, j, pair));
                        }
                    }
                    if (board[(pair.x) % m][(pair.y + n - 1) % n] == word.charAt(j)) {
                        boolean isRepeated = false;
                        Pair tmp = pair.parent;
                        while (tmp != null) {
                            if ((pair.x) % m == tmp.x && (pair.y + n - 1) % n == tmp.y) {
                                isRepeated = true;
                                break;
                            } else {
                                tmp = tmp.parent;
                            }
                        }
                        if (!isRepeated) {
                            stacks.push(new Pair((pair.x) % m, (pair.y + n - 1) % n, j, pair));
                        }
                    }
                } else {
                    retVal = true;
                    break;
                }
            }
        }
        return retVal;
    }

}
