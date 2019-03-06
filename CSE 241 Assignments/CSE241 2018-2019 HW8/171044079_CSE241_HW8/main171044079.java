import java.lang.*;

public class main171044079{
	public static void main (String args[]){
		String[] arr = {new String("This"),new String("is"),new String("a testing string")};
		String[] arr1 = {new String("a testing string"),new String("is"),new String("what"),new String("I"),new String("am")};
		Integer[] arr2 = {new Integer(30),new Integer(40),new Integer(50)};
		Integer[] arr3 = {new Integer(60),new Integer(70),new Integer(80),new Integer(30)};
		String[] arr4 = {new String("is"),new String("what")};
		Integer[] arr5 = {new Integer(60),new Integer(70),new Integer(80)};
		Integer[] arr6 = {};

		HashSet<String> hs = new HashSet<String>(arr);
		HashSet<String> hs1 = new HashSet<String>(arr1);
		HashSet<Integer> hs2 = new HashSet<Integer>(arr2);
		HashSet<Integer> hs3 = new HashSet<Integer>(arr3);

		ArrayList<String> al = new ArrayList<String>(arr);
		ArrayList<String> al1 = new ArrayList<String>(arr1);
		ArrayList<Integer> al2 = new ArrayList<Integer>(arr2);
		ArrayList<Integer> al3 = new ArrayList<Integer>(arr3);

		LinkedList<String> ll = new LinkedList<String>(arr);
		LinkedList<String> ll1 = new LinkedList<String>(arr1);
		LinkedList<Integer> ll2 = new LinkedList<Integer>(arr2);
		LinkedList<Integer> ll3 = new LinkedList<Integer>(arr3);

		System.out.println("\n-----TEST FOR HASHSET-----");
		System.out.println("\n---Contents for HashSet<String> hs---");
		for(int i=0;i<hs.getContArray().length;++i){
			System.out.print(hs.getContArray()[i]+ " ");
		}
		System.out.println("\n\n---Contents for HashSet<String> hs1---");
		for(int i=0;i<hs1.getContArray().length;++i){
			System.out.print(hs1.getContArray()[i]+ " ");
		}
		System.out.println("\n\n---Contents for HashSet<Integer> hs2---");
		for(int i=0;i<hs2.getContArray().length;++i){
			System.out.print(hs2.getContArray()[i]+ " ");
		}
		System.out.println("\n\n---Contents for HashSet<Integer> hs3---");
		for(int i=0;i<hs3.getContArray().length;++i){
			System.out.print(hs3.getContArray()[i]+ " ");
		}
		System.out.println("\n\nTESTING CONTAINS FUNCTION...\nFor HashSet<String> hs, looking for \"CSE241 HW8\" : " + hs.contains("CSE241 HW8"));
		System.out.println("For HashSet<Integer> hs2, looking for 40 : " + hs2.contains(40));

		System.out.println("\nTESTING SIZE FUNCTION...\nFor HashSet<String> hs size is: " +hs.size() + "\nFor HashSet<Integer> hs2 size is: " +hs2.size() );
		
		System.out.println("\nTESTING CONTAINSALL FUNCTION...\nFor HashSet<String> hs and hs1 : " + hs.containsAll(hs1));
		System.out.println("For HashSet<Integer> hs2 and hs3 : " + hs2.containsAll(hs3));

		//Testing for add function
		System.out.println("\nTESTING ADD FUNCTION...\nFor HashSet<String> hs, adding \"CSE241\" also testing adding \"This\"");
		hs.add("CSE241");
		hs.add("This");
		for(int i=0;i<hs.getContArray().length;++i){
			System.out.print(hs.getContArray()[i]+ " ");
		}
		System.out.println("\n\nFor HashSet<Integer> hs2, adding 100 also testing adding 40");
		hs2.add(100);
		hs2.add(40);
		for(int i=0;i<hs2.getContArray().length;++i){
			System.out.print(hs2.getContArray()[i]+ " ");
		}
		//Testing for addAll function
		System.out.println("\n\nTESTING ADDALL FUNCTION...\nFor HashSet<String> hs and hs1");
		hs.addAll(hs1);
		for(int i=0;i<hs.getContArray().length;++i){
			System.out.print(hs.getContArray()[i]+ " ");
		}
		System.out.println("\n\nFor HashSet<Integer> hs2 and hs3");
		hs2.addAll(hs3);
		for(int i=0;i<hs2.getContArray().length;++i){
			System.out.print(hs2.getContArray()[i]+ " ");
		}
		
		//Testing for remove function
		System.out.println("\n\nTESTING REMOVE FUNCTION...\nFor HashSet<String> hs1 removing \"a testing string\"...");
		hs1.remove("a testing string");
		for(int i=0;i<hs1.getContArray().length;++i){
			System.out.print(hs1.getContArray()[i]+ " ");
		}
		System.out.println("\nFor HashSet<Integer> hs3 removing 80...");
		hs3.remove(80);
		for(int i=0;i<hs3.getContArray().length;++i){
			System.out.print(hs3.getContArray()[i]+ " ");
		}

		//Testing for removeAll function
		System.out.println("\n\nTESTING REMOVEALL FUNCTION...\nFor HashSet<String> hs and hs1...");
		hs.removeAll(hs1);
		for(int i=0;i<hs.getContArray().length;++i){
			System.out.print(hs.getContArray()[i]+ " ");
		}
		System.out.println("\nFor HashSet<Integer> hs2 and hs3...");
		hs2.removeAll(hs3);
		for(int i=0;i<hs2.getContArray().length;++i){
			System.out.print(hs2.getContArray()[i]+ " ");
		}

		//Testing for retainAll function
		HashSet<String> hs4 = new HashSet<String>(arr);
		HashSet<Integer> hs5 = new HashSet<Integer>(arr2);
		System.out.println("\n\nTESTING RETAINALL FUNCTION...\nFor HashSet<String> hs and hs4(which has \"This\" \"is\" \"a testing string\")...");
		hs.retainAll(hs4);
		for(int i=0;i<hs.getContArray().length;++i){
			System.out.print(hs.getContArray()[i]+ " ");
		}
		System.out.println("\nFor HashSet<Integer> hs2 and hs5(which has 30 40 50)...");
		hs2.retainAll(hs5);
		for(int i=0;i<hs2.getContArray().length;++i){
			System.out.print(hs2.getContArray()[i]+ " ");
		}
		//Testing for clear and isEmpty function
		System.out.println("\n\nTESTING CLEAR FUNCTION...\nFor HashSet<String> hs clearing...");
		hs.clear();
		System.out.println("Also testing isEmpty for HashSet<String> hs : " + hs.isEmpty());
		System.out.println("\nFor HashSet<Integer> hs2 clearing...");
		hs2.clear();
		System.out.println("Also testing isEmpty for HashSet<Integer> hs2 : " + hs2.isEmpty());




		System.out.println("\n-----TEST FOR ARRAYLIST-----");
		System.out.println("\n---Contents for ArrayList<String> al---");
		for(int i=0;i<al.getContArray().length;++i){
			System.out.print(al.getContArray()[i]+ " ");
		}
		System.out.println("\n\n---Contents for ArrayList<String> al1---");
		for(int i=0;i<al1.getContArray().length;++i){
			System.out.print(al1.getContArray()[i]+ " ");
		}
		System.out.println("\n\n---Contents for ArrayList<Integer> al2---");
		for(int i=0;i<al2.getContArray().length;++i){
			System.out.print(al2.getContArray()[i]+ " ");
		}
		System.out.println("\n\n---Contents for ArrayList<Integer> al3---");
		for(int i=0;i<al3.getContArray().length;++i){
			System.out.print(al3.getContArray()[i]+ " ");
		}

		System.out.println("\n\nTESTING CONTAINS FUNCTION...\nFor ArrayList<String> al, looking for \"CSE241 HW8\" : " + al.contains("CSE241 HW8"));
		System.out.println("For ArrayList<Integer> al2, looking for 40 : " + al2.contains(40));

		System.out.println("\nTESTING SIZE FUNCTION...\nFor ArrayList<String> al size is: " +al.size() + "\nFor ArrayList<Integer> al2 size is: " +al2.size() );
		
		System.out.println("\nTESTING CONTAINSALL FUNCTION...\nFor ArrayList<String> al and al1 : " + al.containsAll(al1));
		System.out.println("For ArrayList<Integer> al2 and al3 : " + al2.containsAll(al3));

		//Testing for add function
		System.out.println("\nTESTING ADD FUNCTION...\nFor ArrayList<String> al, adding \"CSE241\" also testing adding \"This\"");
		al.add("CSE241");
		al.add("This");
		for(int i=0;i<al.getContArray().length;++i){
			System.out.print(al.getContArray()[i]+ " ");
		}
		System.out.println("\n\nFor ArrayList<Integer> al2, adding 100 also testing adding 40");
		al2.add(100);
		al2.add(40);
		for(int i=0;i<al2.getContArray().length;++i){
			System.out.print(al2.getContArray()[i]+ " ");
		}

		//Testing for addAll function
		System.out.println("\n\nTESTING ADDALL FUNCTION...\nFor ArrayList<String> al and al1");
		al.addAll(al1);
		for(int i=0;i<al.getContArray().length;++i){
			System.out.print(al.getContArray()[i]+ " ");
		}
		System.out.println("\n\nFor ArrayList<Integer> al2 and al3");
		al2.addAll(al3);
		for(int i=0;i<al2.getContArray().length;++i){
			System.out.print(al2.getContArray()[i]+ " ");
		}


		//Testing for remove function
		System.out.println("\n\nTESTING REMOVE FUNCTION...\nFor ArrayList<String> al1 removing \"a testing string\"...");
		al1.remove("a testing string");
		for(int i=0;i<al1.getContArray().length;++i){
			System.out.print(al1.getContArray()[i]+ " ");
		}
		System.out.println("\nFor ArrayList<Integer> al3 removing 80...");
		al3.remove(80);
		for(int i=0;i<al3.getContArray().length;++i){
			System.out.print(al3.getContArray()[i]+ " ");
		}

		//Testing for removeAll function
		System.out.println("\n\nTESTING REMOVEALL FUNCTION...\nFor ArrayList<String> al and al1...");
		al.removeAll(al1);
		for(int i=0;i<al.getContArray().length;++i){
			System.out.print(al.getContArray()[i]+ " ");
		}
		System.out.println("\nFor ArrayList<Integer> al2 and al3...");
		al2.removeAll(al3);
		for(int i=0;i<al2.getContArray().length;++i){
			System.out.print(al2.getContArray()[i]+ " ");
		}

		//Testing for retainAll function
		ArrayList<String> al4 = new ArrayList<String>(arr);
		ArrayList<Integer> al5 = new ArrayList<Integer>(arr2);
		System.out.println("\n\nTESTING RETAINALL FUNCTION...\nFor ArrayList<String> al and al4(which has \"This\" \"is\" \"a testing string\")...");
		al.retainAll(al4);
		for(int i=0;i<al.getContArray().length;++i){
			System.out.print(al.getContArray()[i]+ " ");
		}
		System.out.println("\nFor ArrayList<Integer> al2 and al5(which has 30 40 50)...");
		al2.retainAll(al5);
		for(int i=0;i<al2.getContArray().length;++i){
			System.out.print(al2.getContArray()[i]+ " ");
		}

		//Testing for clear and isEmpty function
		System.out.println("\n\nTESTING CLEAR FUNCTION...\nFor ArrayList<String> al clearing...");
		al.clear();
		System.out.println("Also testing isEmpty for ArrayList<String> al : " + al.isEmpty());
		System.out.println("\nFor ArrayList<Integer> al2 clearing...");
		al2.clear();
		System.out.println("Also testing isEmpty for ArrayList<Integer> al2 : " + al2.isEmpty());

		//Linked list tests has to be added
		System.out.println("\n-----TEST FOR LINKEDLIST-----");
		System.out.println("\n---Contents for LinkedList<String> ll---");
		for(int i=0;i<ll.getContArray().length;++i){
			System.out.print(ll.getContArray()[i]+ " ");
		}
		System.out.println("\n\n---Contents for LinkedList<String> ll1---");
		for(int i=0;i<ll1.getContArray().length;++i){
			System.out.print(ll1.getContArray()[i]+ " ");
		}
		System.out.println("\n\n---Contents for LinkedList<Integer> ll2---");
		for(int i=0;i<ll2.getContArray().length;++i){
			System.out.print(ll2.getContArray()[i]+ " ");
		}
		System.out.println("\n\n---Contents for LinkedList<Integer> ll3---");
		for(int i=0;i<ll3.getContArray().length;++i){
			System.out.print(ll3.getContArray()[i]+ " ");
		}

		System.out.println("\n\nTESTING CONTAINS FUNCTION...\nFor LinkedList<String> ll, looking for \"CSE241 HW8\" : " + ll.contains("CSE241 HW8"));
		System.out.println("For LinkedList<Integer> ll2, looking for 40 : " + ll2.contains(40));

		System.out.println("\nTESTING SIZE FUNCTION...\nFor LinkedList<String> ll size is: " +ll.size() + "\nFor LinkedList<Integer> ll2 size is: " +ll2.size() );
		
		System.out.println("\nTESTING CONTAINSALL FUNCTION...\nFor ArrayList<String> ll and ll1 : " + ll.containsAll(ll1));
		System.out.println("For LinkedList<Integer> ll2 and ll3 : " + ll2.containsAll(ll3));

		//Testing for add function
		System.out.println("\nTESTING ADD FUNCTION...\nFor LinkedList<String> ll, adding \"CSE241\" also testing adding \"This\"");
		ll.add("CSE241");
		ll.add("This");
		for(int i=0;i<ll.getContArray().length;++i){
			System.out.print(ll.getContArray()[i]+ " ");
		}
		System.out.println("\n\nFor LinkedList<Integer> ll2, adding 100 also testing adding 40");
		ll2.add(100);
		ll2.add(40);
		for(int i=0;i<ll2.getContArray().length;++i){
			System.out.print(ll2.getContArray()[i]+ " ");
		}

		//Testing for addAll function
		System.out.println("\n\nTESTING ADDALL FUNCTION...\nFor LinkedList<String> ll and ll1");
		ll.addAll(ll1);
		for(int i=0;i<ll.getContArray().length;++i){
			System.out.print(ll.getContArray()[i]+ " ");
		}
		System.out.println("\n\nFor LinkedList<Integer> ll2 and ll3");
		ll2.addAll(ll3);
		for(int i=0;i<ll2.getContArray().length;++i){
			System.out.print(ll2.getContArray()[i]+ " ");
		}

		//Testing for remove function
		System.out.println("\n\nTESTING REMOVE FUNCTION...\nFor LinkedList<String> ll1 removing \"a testing string\"...");
		ll1.remove("a testing string");
		for(int i=0;i<ll1.getContArray().length;++i){
			System.out.print(ll1.getContArray()[i]+ " ");
		}
		System.out.println("\nFor LinkedList<Integer> ll3 removing 60...");
		ll3.remove(60);
		for(int i=0;i<ll3.getContArray().length;++i){
			System.out.print(ll3.getContArray()[i]+ " ");
		}

		LinkedList<String> ll4 = new LinkedList<String>(arr4);
		LinkedList<Integer> ll5 = new LinkedList<Integer>(arr5);
		//Testing for removeAll function
		System.out.println("\n\nTESTING REMOVEALL FUNCTION...\nFor LinkedList<String> ll1 and ll4(which has \"is\" \"what\"...");
		ll1.removeAll(ll4);
		for(int i=0;i<ll1.getContArray().length;++i){
			System.out.print(ll1.getContArray()[i]+ " ");
		}
		System.out.println("\nFor LinkedList<Integer> ll3 and ll5(which has 60 70 80)...");
		ll3.removeAll(ll5);
		for(int i=0;i<ll3.getContArray().length;++i){
			System.out.print(ll3.getContArray()[i]+ " ");
		}

		try{
			//Testing for retainAll function
			LinkedList<String> ll6 = new LinkedList<String>(arr);
			LinkedList<Integer> ll7 = new LinkedList<Integer>(arr5);
			System.out.println("\n\nTESTING RETAINALL FUNCTION...\nFor LinkedList<String> ll and ll6(which has \"This\" \"is\" \"a testing string\")...");
			ll.retainAll(ll6);
			for(int i=0;i<ll.getContArray().length;++i){
				System.out.print(ll.getContArray()[i]+ " ");
			}
			System.out.println("\nFor LinkedList<Integer> ll2 and ll7(which has 60 70 80)...");
			ll2.retainAll(ll7);
			for(int i=0;i<ll2.getContArray().length;++i){
				System.out.print(ll2.getContArray()[i]+ " ");
			}
		}
		catch(RuntimeException e){
			System.out.println("RUNTIME EXCEPTION: Tried to remove the element which is not the head of the linked list.");
		}
		//Test poll function
		System.out.println("\n\nTESTING POLL FUNCTION...\nFor LinkedList<String> ll...");
		System.out.println("Polled head:" + ll.poll());
		for(int i=0;i<ll.getContArray().length;++i){
			System.out.print(ll.getContArray()[i]+ " ");
		}
		System.out.println("\nFor LinkedList<Integer> ll2 ...");
		System.out.println("Polled head:" + ll2.poll());
		for(int i=0;i<ll2.getContArray().length;++i){
			System.out.print(ll2.getContArray()[i]+ " ");
		}

		//Test poll function
		System.out.println("\n\nTESTING ELEMENT FUNCTION...\nFor LinkedList<String> ll...");
		System.out.println("Element:" + ll.element());
		for(int i=0;i<ll.getContArray().length;++i){
			System.out.print(ll.getContArray()[i]+ " ");
		}
		System.out.println("\nFor LinkedList<Integer> ll2 ...");
		System.out.println("Element:" + ll2.element());
		for(int i=0;i<ll2.getContArray().length;++i){
			System.out.print(ll2.getContArray()[i]+ " ");
		}

		//Test poll function
		System.out.println("\n\nTESTING OFFER FUNCTION...\nFor LinkedList<String> ll...");
		ll.offer("Offer");
		for(int i=0;i<ll.getContArray().length;++i){
			System.out.print(ll.getContArray()[i]+ " ");
		}
		System.out.println("\nFor LinkedList<Integer> ll2 ...");
		ll2.offer(40);
		for(int i=0;i<ll2.getContArray().length;++i){
			System.out.print(ll2.getContArray()[i]+ " ");
		}

		//Testing for clear and isEmpty function
		System.out.println("\n\nTESTING CLEAR FUNCTION...\nFor LinkedList<String> ll clearing...");
		ll.clear();
		System.out.println("Also testing isEmpty for LinkedList<String> ll : " + ll.isEmpty());
		System.out.println("\nFor LinkedList<Integer> ll2 clearing...");
		ll2.clear();
		System.out.println("Also testing isEmpty for LinkedList<Integer> ll2 : " + ll2.isEmpty());

		//Exception throws
		LinkedList<Integer> ll8 = new LinkedList<Integer>(arr6);

		System.out.println("\n\nTESTING POLL FUNCTION'S EXCEPTION...\nFor LinkedList<String> ll8 ...");
		try{
			ll8.poll();
		}
		catch(RuntimeException e){
			System.out.println("RUNTIME EXCEPTION : The size of the linked list is 0");
		}
	}
}