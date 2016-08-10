package solution;

import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;

public class Solution {
	public int longestConsecutive(int[] num) {
		int bestLength = 0;
		Set<Integer> set = new HashSet<Integer>();
		for (int i = 0; i < num.length; i++) {
			set.add(num[i]);
		}
		while (set.size() > 0) {
			int length = 1;
			Iterator<Integer> it = set.iterator();
			int begin = it.next();
			int end = begin + 1;// exclusive
			set.remove(begin);
			while (set.contains(begin - 1)) {
				begin--;
				set.remove(begin);
			}
			while (set.contains(end)) {
				set.remove(end);
				end++;
			}
			length = end - begin;
			if (length > bestLength) {
				bestLength = length;
			}
		}
		return bestLength;
	}

	public static void main(String[] argv) {
		Solution s = new Solution();
		int A0[] = { 10, 21, 45, 22, 7, 2, 67, 19, 13, 45, 12, 11, 18, 16, 17,
				100, 201, 20, 101 };
		int A1[] = { 1, 2, 0, 1 };
		System.out.println(s.longestConsecutive(A1));
	}
}
