//
//  test_set_.cpp
//  CS 271 Set Project: Test File
//
//  Created by Aniket Gauba and Ngo Hoang
//
#include "set.cpp"

void test_insert() {
    try {
        Set<int> s;
        s.insert(0);
        string set_str = s.to_string();
        if (s.to_string() != "0") {
            cout << "Incorrect insert result. Expected 0 but got : " << set_str << endl;
        }
        s.insert(2);
        s.insert(-1);
        set_str = s.to_string();
        if (s.to_string() != "-1 2 0") {
            cout << "Incorrect insert result. Expected -1 2 0 but got : " << set_str << endl;
        }
    } catch (exception& e) {
        cerr << "Error inserting into set : " << e.what() << endl;
    }

    try {
        Set<char> s;
        s.insert('a');
        string set_str = s.to_string();
        if (set_str != "a") {
            cout << "Incorrect insert result. Expected a but got : " << set_str << endl;
        }
        s.insert('c');
        s.insert('b');
        set_str = s.to_string();
        if (set_str != "a b c") {
            cout << "Incorrect insert result. Expected a b c but got : " << set_str << endl;
        }
    } catch (exception& e) {
        cerr << "Error inserting into set : " << e.what() << endl;
    }

    try {
        Set<string> s;
        s.insert("apple");
        string set_str = s.to_string();
        if (set_str != "apple") {
            cout << "Incorrect insert result. Expected apple but got : " << set_str << endl;
        }
        s.insert("orange");
        s.insert("banana");
        set_str = s.to_string();
        if (set_str != "apple banana orange") {
            cout << "Incorrect insert result. Expected apple banana orange but got : " << set_str << endl;
        }
    } catch (exception& e) {
        cerr << "Error inserting into set : " << e.what() << endl;
    }

    try {
        Set<float> s;
        s.insert(1.5);
        string set_str = s.to_string();
        if (set_str != "1.5") {
            cout << "Incorrect insert result. Expected 1.5 but got : " << set_str << endl;
        }
        s.insert(2.5);
        s.insert(0.5);
        set_str = s.to_string();
        if (set_str != "0.5 1.5 2.5") {
            cout << "Incorrect insert result. Expected 0.5 1.5 2.5 but got : " << set_str << endl;
        }
    } catch (exception& e) {
        cerr << "Error inserting into set : " << e.what() << endl;
    }
}

void test_remove() {
    try {
        Set<int> s;
        s.insert(1);
        s.insert(2);
        s.insert(3);
        s.insert(4);
        s.remove(5);
        string set_str = s.to_string();
        if (s.to_string() != "4 3 2 1") {
            cout << "Incorrect remove result. Expected 4 3 2 1 but got : " << set_str << endl;
        }
        s.remove(3);
        set_str = s.to_string();
        if(s.to_string() != "4 2 1") {
            cout << "Incorrect remove result. Expected 4 2 1 but got : " << set_str << endl;
        }
    } catch (exception &e) {
        cerr << "Error removing from set : " << e.what() << endl;
    }

    try {
        Set<char> s;
        s.insert('a');
        s.insert('b');
        s.insert('c');
        s.insert('d');
        s.remove('e');  // Removing an element not in the set
        string set_str = s.to_string();
        if (set_str != "a b c d") {
            cout << "Incorrect remove result for char. Expected a b c d but got : " << set_str << endl;
        }
        s.remove('c');
        set_str = s.to_string();
        if (set_str != "a b d") {
            cout << "Incorrect remove result for char. Expected a b d but got : " << set_str << endl;
        }
    } catch (exception& e) {
        cerr << "Error removing from set (char) : " << e.what() << endl;
    }

    try {
        Set<string> s;
        s.insert("apple");
        s.insert("banana");
        s.insert("cherry");
        s.insert("date");
        s.remove("hi");  // Removing an element not in the set
        string set_str = s.to_string();
        if (set_str != "apple banana cherry date") {
            cout << "Incorrect remove result for string. Expected apple banana cherry date but got : " << set_str << endl;
        }
        s.remove("cherry");
        set_str = s.to_string();
        if (set_str != "apple banana date") {
            cout << "Incorrect remove result for string. Expected apple banana date but got : " << set_str << endl;
        }
    } catch (exception& e) {
        cerr << "Error removing from set (string) : " << e.what() << endl;
    }

    try {
        Set<float> s;
        s.insert(1.1);
        s.insert(2.2);
        s.insert(3.3);
        s.insert(4.4);
        s.remove(5.5);  // Removing an element not in the set
        string set_str = s.to_string();
        if (set_str != "1.1 2.2 3.3 4.4") {
            cout << "Incorrect remove result for float. Expected 1.1 2.2 3.3 4.4 but got : " << set_str << endl;
        }
        s.remove(3.3);
        set_str = s.to_string();
        if (set_str != "1.1 2.2 4.4") {
            cout << "Incorrect remove result for float. Expected 1.1 2.2 4.4 but got : " << set_str << endl;
        }
    } catch (exception& e) {
        cerr << "Error removing from set (float) : " << e.what() << endl;
    }   
}

void test_cardinality() {
    try {
        Set<int> s;
        int c = s.cardinality();
        if(c != 0) {
            cout << "Incorrect cardinality. Expected 0 but got : " << c << endl;
        }
        s.insert(6);
        s.insert(5);
        s.insert(4);
        s.insert(3);
        s.insert(2);
        c = s.cardinality();
        if(c != 5) {
            cout << "Incorrect cardinality. Expected 5 but got : " << c << endl;
        }
        s.remove(4);
        s.remove(2);
        c = s.cardinality();
        if(c != 3) {
            cout << "Incorrect cardinality. Expected 3 but got : " << c << endl;
        }
    } catch (exception &e) {
        cerr << "Error in determining set cardinality : " << e.what() << endl;
    }

    try {
        Set<char> s;
        int c = s.cardinality();
        if (c != 0) {
            cout << "Incorrect cardinality for char. Expected 0 but got : " << c << endl;
        }
        s.insert('a');
        s.insert('b');
        s.insert('c');
        c = s.cardinality();
        if (c != 3) {
            cout << "Incorrect cardinality for char. Expected 3 but got : " << c << endl;
        }
        s.remove('b');
        c = s.cardinality();
        if (c != 2) {
            cout << "Incorrect cardinality for char. Expected 2 but got : " << c << endl;
        }
    } catch (exception& e) {
        cerr << "Error in determining set cardinality (char) : " << e.what() << endl;
    }

    try {
        Set<string> s;
        int c = s.cardinality();
        if (c != 0) {
            cout << "Incorrect cardinality for string. Expected 0 but got : " << c << endl;
        }
        s.insert("apple");
        s.insert("banana");
        s.insert("cherry");
        c = s.cardinality();
        if (c != 3) {
            cout << "Incorrect cardinality for string. Expected 3 but got : " << c << endl;
        }
        s.remove("banana");
        c = s.cardinality();
        if (c != 2) {
            cout << "Incorrect cardinality for string. Expected 2 but got : " << c << endl;
        }
    } catch (exception& e) {
        cerr << "Error in determining set cardinality (string) : " << e.what() << endl;
    }

    try {
        Set<float> s;
        int c = s.cardinality();
        if (c != 0) {
            cout << "Incorrect cardinality for float. Expected 0 but got : " << c << endl;
        }
        s.insert(1.1);
        s.insert(2.2);
        s.insert(3.3);
        c = s.cardinality();
        if (c != 3) {
            cout << "Incorrect cardinality for float. Expected 3 but got : " << c << endl;
        }
        s.remove(2.2);
        c = s.cardinality();
        if (c != 2) {
            cout << "Incorrect cardinality for float. Expected 2 but got : " << c << endl;
        }
    } catch (exception& e) {
        cerr << "Error in determining set cardinality (float) : " << e.what() << endl;
    }

    
}

void test_empty() {
    try {
        Set<int> s;
        if(!s.empty()){
            cout << "Empty set identified as non-empty" << endl;
        }
        s.insert(1);
        s.insert(2);
        if(s.empty()) {
            cout << "Non-empty set identified as empty" << endl;
        }
        s.remove(2);
        if(s.empty()) {
            cout << "Non-empty set identified as empty" << endl;
        }
        s.remove(1);
        if(!s.empty()) {
            cout << "Empty set identified as non-empty" << endl;
        }
    } catch (exception &e) {
        cerr << "Error in determining if set is the empty set : " << e.what() << endl;
    }

    try {
        Set<char> s;
        if (!s.empty()) {
            cout << "Empty set (char) identified as non-empty" << endl;
        }
        s.insert('a');
        s.insert('b');
        if (s.empty()) {
            cout << "Non-empty set (char) identified as empty" << endl;
        }
        s.remove('b');
        if (s.empty()) {
            cout << "Non-empty set (char) identified as empty" << endl;
        }
        s.remove('a');
        if (!s.empty()) {
            cout << "Empty set (char) identified as non-empty" << endl;
        }
    } catch (exception& e) {
        cerr << "Error in determining if set is the empty set (char) : " << e.what() << endl;
    }

    try {
        Set<string> s;
        if (!s.empty()) {
            cout << "Empty set (string) identified as non-empty" << endl;
        }
        s.insert("apple");
        s.insert("banana");
        if (s.empty()) {
            cout << "Non-empty set (string) identified as empty" << endl;
        }
        s.remove("banana");
        if (s.empty()) {
            cout << "Non-empty set (string) identified as empty" << endl;
        }
        s.remove("apple");
        if (!s.empty()) {
            cout << "Empty set (string) identified as non-empty" << endl;
        }
    } catch (exception& e) {
        cerr << "Error in determining if set is the empty set (string) : " << e.what() << endl;
    }

    try {
        Set<float> s;
        if (!s.empty()) {
            cout << "Empty set (float) identified as non-empty" << endl;
        }
        s.insert(1.5);
        s.insert(2.5);
        if (s.empty()) {
            cout << "Non-empty set (float) identified as empty" << endl;
        }
        s.remove(2.5);
        if (s.empty()) {
            cout << "Non-empty set (float) identified as empty" << endl;
        }
        s.remove(1.5);
        if (!s.empty()) {
            cout << "Empty set (float) identified as non-empty" << endl;
        }
    } catch (exception& e) {
        cerr << "Error in determining if set is the empty set (float) : " << e.what() << endl;
    }
}

void test_contains() {
    try {
        Set<int> s;
        if(s.contains(5)) {
            cout << "Incorrectly identified 5 as in the set " << s.to_string() << endl;
        }
        s.insert(1);
        s.insert(2);
        s.insert(3);
        if(s.contains(5)) {
            cout << "Incorrectly identified 5 as in the set " << s.to_string() << endl;
        }
        if(!s.contains(2)) {
            cout << "Incorrectly identified 2 as NOT in the set " << s.to_string() << endl;
        }
    } catch (exception &e) {
        cerr << "Error in determining if value contained in se : " << e.what() << endl;
    }

    try {
        Set<char> s;
        if (s.contains('a')) {
            cout << "Incorrectly identified 'a' as in the set " << s.to_string() << endl;
        }
        s.insert('x');
        s.insert('y');
        s.insert('z');
        if (s.contains('a')) {
            cout << "Incorrectly identified 'a' as in the set " << s.to_string() << endl;
        }
        if (!s.contains('y')) {
            cout << "Incorrectly identified 'y' as NOT in the set " << s.to_string() << endl;
        }
    } catch (exception& e) {
        cerr << "Error in determining if value contained in set (char) : " << e.what() << endl;
    }

    try {
        Set<string> s;
        if (s.contains("apple")) {
            cout << "Incorrectly identified 'apple' as in the set " << s.to_string() << endl;
        }
        s.insert("orange");
        s.insert("banana");
        s.insert("cherry");
        if (s.contains("apple")) {
            cout << "Incorrectly identified 'apple' as in the set " << s.to_string() << endl;
        }
        if (!s.contains("banana")) {
            cout << "Incorrectly identified 'banana' as NOT in the set " << s.to_string() << endl;
        }
    } catch (exception& e) {
        cerr << "Error in determining if value contained in set (string) : " << e.what() << endl;
    }

    try {
        Set<float> s;
        if (s.contains(1.5)) {
            cout << "Incorrectly identified 1.5 as in the set " << s.to_string() << endl;
        }
        s.insert(2.2);
        s.insert(3.3);
        s.insert(4.4);
        if (s.contains(1.5)) {
            cout << "Incorrectly identified 1.5 as in the set " << s.to_string() << endl;
        }
        if (!s.contains(3.3)) {
            cout << "Incorrectly identified 3.3 as NOT in the set " << s.to_string() << endl;
        }
    } catch (exception& e) {
        cerr << "Error in determining if value contained in set (float) : " << e.what() << endl;
    }
}

void test_equality() {
    try {
        Set<int> s;
        Set<int> t;
        if(!(s==t)) {
            cout << "Empty sets should be considered equal" << endl;
        }
        s.insert(1);
        s.insert(2);
        s.insert(3);
        if(s==t) {
            cout << "Incorrectly identified set " << s.to_string() << " as equivalent to " << t.to_string() << endl;
        }
        t.insert(1);
        t.insert(2);
        t.insert(3);
        if(!(s==t)) {
            cout << "Sets " << s.to_string() << " and " << t.to_string() << " should be considered equal." << endl;
        }
        s.remove(3);
        if(s==t) {
            cout << "Incorrectly identified set " << s.to_string() << " as equivalent to " << t.to_string() << endl;
        }
    } catch (exception &e) {
        cerr << "Error in determining set equality : " << e.what() << endl;
    }

    try {
        Set<char> s;
        Set<char> t;
        if (!(s == t)) {
            cout << "Empty sets (char) should be considered equal" << endl;
        }
        s.insert('a');
        s.insert('b');
        s.insert('c');
        if (s == t) {
            cout << "Incorrectly identified set (char) " << s.to_string() << " as equivalent to " << t.to_string() << endl;
        }
        t.insert('a');
        t.insert('b');
        t.insert('c');
        if (!(s == t)) {
            cout << "Sets (char) " << s.to_string() << " and " << t.to_string() << " should be considered equal." << endl;
        }
        s.remove('c');
        if (s == t) {
            cout << "Incorrectly identified set (char) " << s.to_string() << " as equivalent to " << t.to_string() << endl;
        }
    } catch (exception& e) {
        cerr << "Error in determining set equality (char) : " << e.what() << endl;
    }

    try {
        Set<string> s;
        Set<string> t;
        if (!(s == t)) {
            cout << "Empty sets (string) should be considered equal" << endl;
        }
        s.insert("apple");
        s.insert("banana");
        s.insert("cherry");
        if (s == t) {
            cout << "Incorrectly identified set (string) " << s.to_string() << " as equivalent to " << t.to_string() << endl;
        }
        t.insert("apple");
        t.insert("banana");
        t.insert("cherry");
        if (!(s == t)) {
            cout << "Sets (string) " << s.to_string() << " and " << t.to_string() << " should be considered equal." << endl;
        }
        s.remove("cherry");
        if (s == t) {
            cout << "Incorrectly identified set (string) " << s.to_string() << " as equivalent to " << t.to_string() << endl;
        }
    } catch (exception& e) {
        cerr << "Error in determining set equality (string) : " << e.what() << endl;
    }

    try {
        Set<float> s;
        Set<float> t;
        if (!(s == t)) {
            cout << "Empty sets (float) should be considered equal" << endl;
        }
        s.insert(1.1);
        s.insert(2.2);
        s.insert(3.3);
        if (s == t) {
            cout << "Incorrectly identified set (float) " << s.to_string() << " as equivalent to " << t.to_string() << endl;
        }
        t.insert(1.1);
        t.insert(2.2);
        t.insert(3.3);
        if (!(s == t)) {
            cout << "Sets (float) " << s.to_string() << " and " << t.to_string() << " should be considered equal." << endl;
        }
        s.remove(3.3);
        if (s == t) {
            cout << "Incorrectly identified set (float) " << s.to_string() << " as equivalent to " << t.to_string() << endl;
        }
    } catch (exception& e) {
        cerr << "Error in determining set equality (float) : " << e.what() << endl;
    }

}

void test_subset() {
    try {
        Set<int> s;
        Set<int> t;
        if(!(s<=t)) {
            cout << "Set " << s.to_string() << " should be considered a subset of the set " << t.to_string() << endl;
        }
        t.insert(3);
        t.insert(7);
        if(!(s<=t)) {
            cout << "Set " << s.to_string() << " should be considered a subset of the set " << t.to_string() << endl;
        }
        s.insert(7);
        s.insert(3);
        if(!(s<=t)) {
            cout << "Set " << s.to_string() << " should be considered a subset of the set " << t.to_string() << endl;
        }
        t.insert(10);
        if(!(s<=t)) {
            cout << "Set " << s.to_string() << " should be considered a subset of the set " << t.to_string() << endl;
        }
        s.insert(11);
        if(s<=t) {
            cout << "Set " << s.to_string() << " should NOT be considered a subset of the set " << t.to_string() << endl;
        }
    } catch (exception& e) {
        cerr << "Error in determining subset : " << e.what() << endl;
    }

    try {
        Set<char> s;
        Set<char> t;
        if (!(s <= t)) {
            cout << "Empty sets (char) should be considered subsets" << endl;
        }
        s.insert('a');
        s.insert('b');
        t.insert('a');
        t.insert('b');
        t.insert('c');
        if (!(s <= t)) {
            cout << "Set (char) " << s.to_string() << " should be considered a subset of the set " << t.to_string() << endl;
        }
        t.remove('a');
        if (s <= t) {
            cout << "Set (char) " << s.to_string() << " incorrectly identified as a subset of " << t.to_string() << endl;
        }
    } catch (exception& e) {
        cerr << "Error in determining set subset (char) : " << e.what() << endl;
    }

    try {
        Set<string> s;
        Set<string> t;
        if (!(s <= t)) {
            cout << "Empty sets (string) should be considered subsets" << endl;
        }
        s.insert("apple");
        s.insert("banana");
        t.insert("apple");
        t.insert("banana");
        t.insert("cherry");
        if (!(s <= t)) {
            cout << "Set (string) " << s.to_string() << " should be considered a subset of the set " << t.to_string() << endl;
        }
        t.remove("banana");
        if (s <= t) {
            cout << "Set (string) " << s.to_string() << " incorrectly identified as a subset of " << t.to_string() << endl;
        }
    } catch (exception& e) {
        cerr << "Error in determining set subset (string) : " << e.what() << endl;
    }

    try {
        Set<float> s;
        Set<float> t;
        if (!(s <= t)) {
            cout << "Empty sets (float) should be considered subsets" << endl;
        }
        s.insert(1.1);
        s.insert(2.2);
        t.insert(1.1);
        t.insert(2.2);
        t.insert(3.3);
        if (!(s <= t)) {
            cout << "Set (float) " << s.to_string() << " should be considered a subset of the set " << t.to_string() << endl;
        }
        t.remove(2.2);
        if (s <= t) {
            cout << "Set (float) " << s.to_string() << " incorrectly identified as a subset of " << t.to_string() << endl;
        }
    } catch (exception& e) {
        cerr << "Error in determining set subset (float) : " << e.what() << endl;
    }
}

void test_union() {
    try {
        Set<int> s;
        Set<int> t;
        string set_str = (s+t).to_string();
        if(set_str != "") {
            cout << "Union of the empty sets should be the empty set. Instead got : " << set_str << endl;
        }
        s.insert(1);
        s.insert(2);
        t.insert(2);
        t.insert(1);
        set_str = (s+t).to_string();
        if(set_str != "2 1") {
            cout << "Union of " << s.to_string() << " and " << t.to_string() << " was expected to be 2 1 but instead got : " << set_str << endl;
        }
        t.insert(6);
        set_str = (s+t).to_string();
        if(set_str != "2 1 6") {
            cout << "Union of " << s.to_string() << " and " << t.to_string() << " was expected to be 2 1 6 but instead got : " << set_str << endl;
        }
    } catch (exception& e) {
        cerr << "Error in generating the union set : " << e.what() << endl;
    }

    try {
        Set<char> s;
        Set<char> t;
        string set_str = (s + t).to_string();
        if (set_str != "") {
            cout << "Union of empty sets (char) should be the empty set. Instead got : " << set_str << endl;
        }
        s.insert('a');
        s.insert('b');
        t.insert('b');
        t.insert('a');
        set_str = (s + t).to_string();
        if (set_str != "a b") {
            cout << "Union of " << s.to_string() << " and " << t.to_string() << " was expected to be a b but instead got : " << set_str << endl;
        }
        t.insert('c');
        set_str = (s + t).to_string();
        if (set_str != "a b c") {
            cout << "Union of " << s.to_string() << " and " << t.to_string() << " was expected to be a b c but instead got : " << set_str << endl;
        }
    } catch (exception& e) {
        cerr << "Error in generating the union set (char) : " << e.what() << endl;
    }

    try {
        Set<string> s;
        Set<string> t;
        string set_str = (s + t).to_string();
        if (set_str != "") {
            cout << "Union of empty sets (string) should be the empty set. Instead got : " << set_str << endl;
        }
        s.insert("apple");
        s.insert("banana");
        t.insert("banana");
        t.insert("apple");
        set_str = (s + t).to_string();
        if (set_str != "apple banana") {
            cout << "Union of " << s.to_string() << " and " << t.to_string() << " was expected to be apple banana but instead got : " << set_str << endl;
        }
        t.insert("cherry");
        set_str = (s + t).to_string();
        if (set_str != "apple banana cherry") {
            cout << "Union of " << s.to_string() << " and " << t.to_string() << " was expected to be apple banana cherry but instead got : " << set_str << endl;
        }
    } catch (exception& e) {
        cerr << "Error in generating the union set (string) : " << e.what() << endl;
    }

    try {
        Set<float> s;
        Set<float> t;
        string set_str = (s + t).to_string();
        if (set_str != "") {
            cout << "Union of empty sets (float) should be the empty set. Instead got : " << set_str << endl;
        }
        s.insert(1.1);
        s.insert(2.2);
        t.insert(2.2);
        t.insert(1.1);
        set_str = (s + t).to_string();
        if (set_str != "1.1 2.2") {
            cout << "Union of " << s.to_string() << " and " << t.to_string() << " was expected to be 1.1 2.2 but instead got : " << set_str << endl;
        }
        t.insert(3.3);
        set_str = (s + t).to_string();
        if (set_str != "1.1 2.2 3.3") {
            cout << "Union of " << s.to_string() << " and " << t.to_string() << " was expected to be 1.1 2.2 3.3 but instead got : " << set_str << endl;
        }
    } catch (exception& e) {
        cerr << "Error in generating the union set (float) : " << e.what() << endl;
    }
}

void test_intersection() {
    try {
        Set<int> s;
        Set<int> t;
        string set_str = (s&t).to_string();
        if(set_str != "") {
            cout << "Intersection of the empty sets should be the empty set. Instead got : " << set_str << endl;
        }
        s.insert(1);
        s.insert(2);
        t.insert(6);
        set_str = (s&t).to_string();
        if(set_str != "") {
            cout << "Intersection of " << s.to_string() << " and " << t.to_string() << " was expected to be the empty set but instead got : " << set_str << endl;
        }
        t.insert(2);
        t.insert(1);
        set_str = (s&t).to_string();
        if(set_str != "1 2") {
            cout << "Intersection of " << s.to_string() << " and " << t.to_string() << " was expected to be 1 2 but instead got : " << set_str << endl;
        }
    } catch (exception& e) {
        cerr << "Error in generating the intersection set : " << e.what() << endl;
    }

    try {
        Set<char> s;
        Set<char> t;
        string set_str = (s & t).to_string();
        if (set_str != "") {
            cout << "Intersection of empty sets (char) should be the empty set. Instead got : " << set_str << endl;
        }
        s.insert('a');
        s.insert('b');
        t.insert('c');
        set_str = (s & t).to_string();
        if (set_str != "") {
            cout << "Intersection of " << s.to_string() << " and " << t.to_string() << " was expected to be the empty set but instead got : " << set_str << endl;
        }
        t.insert('b');
        t.insert('a');
        set_str = (s & t).to_string();
        if (set_str != "a b") {
            cout << "Intersection of " << s.to_string() << " and " << t.to_string() << " was expected to be a b but instead got : " << set_str << endl;
        }
    } catch (exception& e) {
        cerr << "Error in generating the intersection set (char) : " << e.what() << endl;
    }

    try {
        Set<string> s;
        Set<string> t;
        string set_str = (s & t).to_string();
        if (set_str != "") {
            cout << "Intersection of empty sets (string) should be the empty set. Instead got : " << set_str << endl;
        }
        s.insert("apple");
        s.insert("banana");
        t.insert("cherry");
        set_str = (s & t).to_string();
        if (set_str != "") {
            cout << "Intersection of " << s.to_string() << " and " << t.to_string() << " was expected to be the empty set but instead got : " << set_str << endl;
        }
        t.insert("banana");
        t.insert("apple");
        set_str = (s & t).to_string();
        if (set_str != "apple banana") {
            cout << "Intersection of " << s.to_string() << " and " << t.to_string() << " was expected to be apple banana but instead got : " << set_str << endl;
        }
    } catch (exception& e) {
        cerr << "Error in generating the intersection set (string) : " << e.what() << endl;
    }

    try {
        Set<float> s;
        Set<float> t;
        string set_str = (s & t).to_string();
        if (set_str != "") {
            cout << "Intersection of empty sets (float) should be the empty set. Instead got : " << set_str << endl;
        }
        s.insert(1.1);
        s.insert(2.2);
        t.insert(3.3);
        set_str = (s & t).to_string();
        if (set_str != "") {
            cout << "Intersection of " << s.to_string() << " and " << t.to_string() << " was expected to be the empty set but instead got : " << set_str << endl;
        }
        t.insert(2.2);
        t.insert(1.1);
        set_str = (s & t).to_string();
        if (set_str != "1.1 2.2") {
            cout << "Intersection of " << s.to_string() << " and " << t.to_string() << " was expected to be 1.1 2.2 but instead got : " << set_str << endl;
        }
    } catch (exception& e) {
        cerr << "Error in generating the intersection set (float) : " << e.what() << endl;
    }
}

void test_diff() {
    try {
        Set<int> s;
        Set<int> t;
        string set_str = (s-t).to_string();
        if(set_str != "") {
            cout << "Difference of the empty sets should be the empty set. Instead got : " << set_str << endl;
        }
        s.insert(1);
        s.insert(2);
        t.insert(6);
        set_str = (s-t).to_string();
        if(set_str != "1 2") {
            cout << "Set " << s.to_string() << " \\ Set " << t.to_string() << " was expected to be 1 2 set but instead got : " << set_str << endl;
        }
        t.insert(2);
        t.insert(1);
        set_str = (s-t).to_string();
        if(set_str != "") {
            cout << "Set " << s.to_string() << " \\ Set " << t.to_string() << " was expected to be the empty set set but instead got : " << set_str << endl;
        }
    } catch (exception& e) {
        cerr << "Error in generating the intersection set : " << e.what() << endl;
    }

    try {
        Set<char> s;
        Set<char> t;
        string set_str = (s - t).to_string();
        if (set_str != "") {
            cout << "Difference of empty sets (char) should be the empty set. Instead got : " << set_str << endl;
        }
        s.insert('a');
        s.insert('b');
        s.insert('c');
        t.insert('d');
        set_str = (s - t).to_string();
        if (set_str != "a b c") {
            cout << "Difference of " << s.to_string() << " and " << t.to_string() << " was expected to be a b c but instead got : " << set_str << endl;
        }
        t.insert('b');
        set_str = (s - t).to_string();
        if (set_str != "a c") {
            cout << "Difference of " << s.to_string() << " and " << t.to_string() << " was expected to be a c but instead got : " << set_str << endl;
        }
    } catch (exception& e) {
        cerr << "Error in generating the difference set (char) : " << e.what() << endl;
    }

    try {
        Set<string> s;
        Set<string> t;
        string set_str = (s - t).to_string();
        if (set_str != "") {
            cout << "Difference of empty sets (string) should be the empty set. Instead got : " << set_str << endl;
        }
        s.insert("apple");
        s.insert("banana");
        s.insert("cherry");
        t.insert("date");
        set_str = (s - t).to_string();
        if (set_str != "apple banana cherry") {
            cout << "Difference of " << s.to_string() << " and " << t.to_string() << " was expected to be apple banana cherry but instead got : " << set_str << endl;
        }
        t.insert("banana");
        set_str = (s - t).to_string();
        if (set_str != "apple cherry") {
            cout << "Difference of " << s.to_string() << " and " << t.to_string() << " was expected to be apple cherry but instead got : " << set_str << endl;
        }
    } catch (exception& e) {
        cerr << "Error in generating the difference set (string) : " << e.what() << endl;
    }

    try {
        Set<float> s;
        Set<float> t;
        string set_str = (s - t).to_string();
        if (set_str != "") {
            cout << "Difference of empty sets (float) should be the empty set. Instead got : " << set_str << endl;
        }
        s.insert(1.1f);
        s.insert(2.2f);
        s.insert(3.3f);
        t.insert(4.4f);
        set_str = (s - t).to_string();
        if (set_str != "1.1 2.2 3.3") {
            cout << "Difference of " << s.to_string() << " and " << t.to_string() << " was expected to be 1.1 2.2 3.3 but instead got : " << set_str << endl;
        }
        t.insert(2.2f);
        set_str = (s - t).to_string();
        if (set_str != "1.1 3.3") {
            cout << "Difference of " << s.to_string() << " and " << t.to_string() << " was expected to be 1.1 3.3 but instead got : " << set_str << endl;
        }
    } catch (exception& e) {
        cerr << "Error in generating the difference set (float) : " << e.what() << endl;
    }


}

void time_test() {
    Set<int> S;
    for (int i = 0; i < 500000; i++ )
    	{
    		S.insert(rand() / 5000000);
    	}
    Set<int> T;
    for (int i = 0; i < 500000; i++ )
    	{
    		T.insert(rand() / 500000);
    	}
    int total = 0;

    int val = rand()%100000;
    auto begin = std::chrono::high_resolution_clock::now();
    S.insert(val);
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "insert time test took " << elapsed.count() << " nanoseconds" << endl;
    total+=elapsed.count();

    begin = std::chrono::high_resolution_clock::now();
    S.remove(val);
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "remove time test took " << elapsed.count() << " nanoseconds" << endl;
    total+=elapsed.count();

    begin = std::chrono::high_resolution_clock::now();
    S.cardinality();
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "cardinality time test took " << elapsed.count() << " nanoseconds" << endl;
    total+=elapsed.count();


    begin = std::chrono::high_resolution_clock::now();
    S.empty();
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "empty time test took " << elapsed.count() << " nanoseconds" << endl;
    total+=elapsed.count();

    val = rand()%100000;
    begin = std::chrono::high_resolution_clock::now();
    bool r = S.contains(val);
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "contains time test took " << elapsed.count() << " nanoseconds" << endl;
    total+=elapsed.count();


    begin = std::chrono::high_resolution_clock::now();
    r = (S==T);
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "equality time test took " << elapsed.count() << " nanoseconds" << endl;
    total+=elapsed.count();


    begin = std::chrono::high_resolution_clock::now();
    r = (S<=T);
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "subset time test took " << elapsed.count() << " nanoseconds" << endl;
    total+=elapsed.count();


    begin = std::chrono::high_resolution_clock::now();
    Set<int> U = (S+T);
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "union time test took " << elapsed.count() << " nanoseconds" << endl;
    total+=elapsed.count();


    begin = std::chrono::high_resolution_clock::now();
    U = (S&T);
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "intersection time test took " << elapsed.count() << " nanoseconds" << endl;
    total+=elapsed.count();


    begin = std::chrono::high_resolution_clock::now();
    U = (S-T);
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "difference time test took " << elapsed.count() << " nanoseconds" << endl;
    total+=elapsed.count();
    cout << "Total time: " << total << endl;
}

int main() {
    test_insert();
    test_remove();
    test_cardinality();
    test_empty();
    test_contains();
    test_equality();
    test_subset();
    test_union();
    test_intersection();
    test_diff();

    time_test();
    
    cout << "Testing completed" << endl;
    
    return 0;
}



