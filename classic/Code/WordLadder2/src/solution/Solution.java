package solution;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;
import java.util.Set;
import java.util.Stack;

public class Solution {
	class Node {
		String val;
		List<Node> children;
		Node parent;

		Node(String input, Node _parent) {
			val = input;
			children = new ArrayList<Node>();
			parent = _parent;
		}

		boolean isParentContains(String child) {
			Node _parent = this;
			while (_parent != null) {
				if (_parent.val.equals(child)) {
					return true;
				}
				_parent = _parent.parent;
			}
			return false;
		}
	}

	String candidate = "abcdefghijklmnopqrstuvwxyz";
	Queue<Node> queue = new LinkedList<Node>();
	Set<ArrayList<String>> set = new HashSet<ArrayList<String>>();
	static final String NULL = "NULL";
	Node ROOT;

	void checkBFS(Node root) {
		if (root == null)
			return;
		queue.add(root);
		while (queue.size() > 0) {
			Node node = queue.remove();
			if (node != null) {
				for (int i = 0; i < node.children.size(); i++) {
					queue.add(root.children.get(i));
				}
			}
		}
	}

	ArrayList<ArrayList<String>> parseMin(ArrayList<ArrayList<String>> input) {
		int min = 1000;
		for (int i = 0; i < input.size(); i++) {
			if (input.get(i).size() < min) {
				min = input.get(i).size();
			}
		}
		ArrayList<ArrayList<String>> list = new ArrayList<ArrayList<String>>();
		for (int i = 0; i < input.size(); i++) {
			if (input.get(i).size() == min) {
				list.add(input.get(i));
			}
		}
		return list;
	}

	boolean equal(ArrayList<String> a, ArrayList<String> b) {
		if (a.size() != b.size()) {
			return false;
		}
		for (int i = 0; i < a.size(); i++) {
			if (!a.get(i).equals(b.get(i))) {
				return false;
			}
		}
		return true;
	}

	public ArrayList<ArrayList<String>> findLadders(String start, String end,
			HashSet<String> dict) {
		Node root = new Node(start, null);
		ROOT = root;
		recursiveFind(root, start, end, dict);
		ArrayList<ArrayList<String>> result = printOut(root, end);
		// while (!root.val.equals(NULL)) {
		// ArrayList<String> ladder = new ArrayList<String>();
		// ladder.add(root.val);
		// ArrayList<String> tmp = printOut(root, ladder);
		// boolean skip = false;
		// for (int i = 0; i < result.size(); i++) {
		// if (equal(result.get(i), tmp))
		// skip = true;
		// }
		// if (tmp.size() == 1)
		// break;
		// if (tmp == null || tmp.size() == 0) {
		// return result;
		// }
		// if (tmp.get(tmp.size() - 1).equals(end) && !skip) {
		// result.add(tmp);
		// }
		// }
		result = parseMin(result);
		return result;
	}

	boolean isNull(Node input) {
		if (input == null)
			return true;
		if (input.children == null)
			return true;
		if (input.children.size() == 0)
			return true;
		for (int i = 0; i < input.children.size(); i++) {
			if (input.children.get(i) != null)
				return false;
		}
		return true;
	}

	ArrayList<ArrayList<String>> printOut(Node root, String end) {
		Stack<Node> stack = new Stack<Node>();
		List<Node> validLeaves = new ArrayList<Node>();
		if (root.children != null && root.children.size() != 0) {
			stack.add(root);
		} else {
			return new ArrayList<ArrayList<String>>();
		}
		while (!stack.isEmpty()) {
			Node node = stack.pop();
			if (node.children == null || node.children.size() == 0) {
				if (node.val.equals(end))
					validLeaves.add(node);
				continue;
			} else {
				for (int i = 0; i < node.children.size(); i++) {
					stack.add(node.children.get(i));
				}
			}
		}
		ArrayList<ArrayList<String>> lists = new ArrayList<ArrayList<String>>();
		for (int i = 0; i < validLeaves.size(); i++) {
			ArrayList<String> list = new ArrayList<String>();
			Node node = validLeaves.get(i);
			while (node != null) {
				list.add(0, node.val);
				node = node.parent;
			}
			lists.add(list);
		}
		return lists;
	}

	ArrayList<String> printOut(Node root, ArrayList<String> result) {
		if (root.val == null || root.children == null
				|| root.children.size() == 0) {
			return result;
		}
		if (!result.contains(root.children.get(0).val)) {
			result.add(root.children.get(0).val);
		} else {
			result.add("error");
			return result;
		}
		if (root.children.get(0).children == null
				|| root.children.get(0).children.size() == 0
				|| isNull(root.children.get(0)))
			root.children.remove(0);
		if (root.children.size() > 0)
			result = printOut(root.children.get(0), result);
		else {
			if (root == ROOT) {
				root.val = NULL;
			}
		}
		return result;
	}

	void recursiveFind(Node entrance, String start, String end,
			HashSet<String> dict) {
		for (int i = 0; i < start.length(); i++) {
			for (int j = 0; j < candidate.length(); j++) {
				String tmp = "";
				for (int k = 0; k < start.length(); k++) {
					if (i != k)
						tmp += "" + start.charAt(k);
					else
						tmp += "" + candidate.charAt(j);
				}
				start.replace(start.charAt(i), candidate.charAt(j));
				if (dict.contains(tmp)) {
					if (!entrance.isParentContains(tmp)) {
						Node newNode = new Node(tmp, entrance);
						entrance.children.add(newNode);
					}
				}
			}
		}
		if (entrance.children == null || entrance.children.size() == 0) {
			return;
		}
		for (int i = 0; i < entrance.children.size(); i++) {
			if (entrance.children.get(i) == null)
				continue;
			String tmp = entrance.children.get(i).val;
			if (tmp != null && !tmp.equals(end)) {
				recursiveFind(entrance.children.get(i),
						entrance.children.get(i).val, end, dict);
			}
		}
	}

	void print(ArrayList<ArrayList<String>> result) {
		for (int i = 0; i < result.size(); i++) {
			for (int j = 0; j < result.get(i).size(); j++) {
				System.out.print(" " + result.get(i).get(j));
			}
			System.out.println("");
		}
	}

	void test(String[] input) {
		String[] dict = input;
		HashSet<String> set = new HashSet<String>();
		for (int i = 0; i < dict.length; i++) {
			set.add(dict[i]);
		}
		ArrayList<ArrayList<String>> result = findLadders("a", "c", set);
		print(result);
	}

	void test(String a, String b, String[] input) {
		String[] dict = input;
		HashSet<String> set = new HashSet<String>();
		for (int i = 0; i < dict.length; i++) {
			set.add(dict[i]);
		}
		ArrayList<ArrayList<String>> result = findLadders(a, b, set);
		print(result);
	}

	public static void main4(String[] argv) {
		Solution s = new Solution();
		String[] input = { "a", "b", "c" };
		s.test(input);
	}

	public static void main3(String[] argv) {
		Solution s = new Solution();
		String[] input = { "hot", "dog" };
		s.test("hot", "dog", input);
	}

	public static void main1(String[] argv) {
		Solution s = new Solution();
		String[] input = { "hot", "dog", "dot" };
		s.test("hot", "dog", input);
	}

	public static void main5(String[] argv) {
		Solution s = new Solution();
		String[] input = { "hot", "cog", "dot", "dog", "hit", "lot", "log" };
		s.test("hit", "cog", input);
		/*
		 * [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
		 */
	}

	public static void main9(String[] argv) {
		Solution s = new Solution();
		String[] input = { "hot", "cog", "dog", "tot", "hog", "hop", "pot",
				"dot" };
		s.test("hot", "dog", input);
	}

	public static void main(String[] argv) {
		Solution s = new Solution();
		String[] input = { "lest", "leet", "lose", "code", "lode", "robe",
				"lost" };
		s.test("leet", "code", input);
	}

	public static void main7(String[] argv) {
		Solution s = new Solution();
		String[] input = { "hot", "cog", "dot", "dog", "hit", "lot", "log" };
		s.test("hit", "cog", input);
		/*
		 * wrong: hit hot dot lot cog ;hit hot lot dot cog
		 */
		/*
		 * correct: hit","hot","lot","log","cog"]
		 */
	}

	public static void main6(String[] argv) {
		Solution s = new Solution();
		String[] input = { "hot", "dog", "cog", "pot", "dot" };
		s.test("hot", "dog", input);
		/*
		 * answer: hot","dot","dog", etc.
		 */
		/*
		 * input:"hot","dog","cog","pot","dot"
		 */
	}

	public static void main8(String[] argv) {
		Solution s = new Solution();
		String[] input = { "si", "go", "se", "cm", "so", "ph", "mt", "db",
				"mb", "sb", "kr", "ln", "tm", "le", "av", "sm", "ar", "ci",
				"ca", "br", "ti", "ba", "to", "ra", "fa", "yo", "ow", "sn",
				"ya", "cr", "po", "fe", "ho", "ma", "re", "or", "rn", "au",
				"ur", "rh", "sr", "tc", "lt", "lo", "as", "fr", "nb", "yb",
				"if", "pb", "ge", "th", "pm", "rb", "sh", "co", "ga", "li",
				"ha", "hz", "no", "bi", "di", "hi", "qa", "pi", "os", "uh",
				"wm", "an", "me", "mo", "na", "la", "st", "er", "sc", "ne",
				"mn", "mi", "am", "ex", "pt", "io", "be", "fm", "ta", "tb",
				"ni", "mr", "pa", "he", "lr", "sq", "ye" };
		s.test("qa", "sq", input);
	}

	public static void main2(String[] argv) {
		Scanner scanner;
		HashSet<String> set = new HashSet<String>();
		try {
			scanner = new Scanner(new FileReader("dictionary.txt"));

			while (scanner.hasNextLine()) {

				String column = scanner.nextLine();
				set.add(column);
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		Solution s = new Solution();
		ArrayList<ArrayList<String>> result;// = s.findLadders("a", "c", set);
		result = s.findLadders("bat", "cat", set);
		s.print(result);
	}

}
