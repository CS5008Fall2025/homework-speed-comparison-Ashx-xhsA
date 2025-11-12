# Report for Data Structure Speed Comparison Homework

Make sure to answer every question in this homework. You should not bullet point your answers, but
instead write them as a full report format. This doesn't mean you have to be wordy, as concise is good,
but it does mean you need to use proper grammar, spelling, and be complete. For question that just
ask for a short answer, answer accordingly. Make sure to include references where appropriate.

## Algorithmic Analysis - Big $O$

Complete the Big O table below for the following functions. You may use any resource you like, but
for the SortedVector and SortedList, you should use the Big O for the functions you wrote in the
the homework. Both Single and Double Linked List you can assume head and tail pointers are available. 
Don't forget to use latex math notation (example in the table).

### Big $O$ Table

| -                         | Add/Insert |   Remove   | Search/Find |    Sort    | Add Front | Add Back | Remove Front | Remove Back | Get by Index |
| ------------------------- | :--------: | :--------: | :---------: | :--------: | :-------: | :------: | :----------: | :---------: | :----------: |
| Vector                    |   $O(n)$   |   $O(n)$   |   $O(n)$    | $O(nlogn)$ |  $O(n)$   |  $O(1)$  |    $O(n)$    |   $O(1)$    |    $O(1)$    |
| Single Linked List        |   $O(1)$   |   $O(n)$   |   $O(n)$    | $O(nlogn)$ |  $O(1)$   |  $O(1)$  |    $O(1)$    |   $O(n)$    |    $O(n)$    |
| Double Linked List        |   $O(1)$   |   $O(n)$   |   $O(n)$    | $O(nlogn)$ |  $O(1)$   |  $O(1)$  |    $O(1)$    |   $O(1)$    |    $O(n)$    |
| Sorted Vector             |   $O(n)$   |   $O(n)$   | $O(nlogn)$  |   $O(1)$   |    ---    |   ---    |     ---      |     ---     |     ---      |
| Sorted Single Linked List |   $O(n)$   |   $O(n)$   |   $O(n)$    |   $O(1)$   |    ---    |   ---    |     ---      |     ---     |     ---      |
| Sorted Double Linked List |   $O(n)$   |   $O(n)$   |   $O(n)$    |   $O(1)$   |    ---    |   ---    |     ---      |     ---     |     ---      |
| Binary Search Tree        | $O(nlogn)$ | $O(nlogn)$ | $O(nlogn)$  |   $O(n)$   |    ---    |   ---    |     ---      |     ---     |     ---      |

For Sort, we are asking for the Big $O$ for taking the current data structure and writing it 'sorted' to a file. However, not the file writes. For example, if you have a vector of 1000 elements, and you want to write it to a file, you would need to sort it first. So, the Big $O$ for this would be the Big $O$ for sorting. For BST, you have to convert the tree to a sequential structure, so the cost of doing that.  

### Assumptions with Sort

Since the worst case can change considerably based on what sort you use for sorting (if any), list each algorithm below, and specify the algorithm used in your assumption.  For BST, write which  method of traversal you would use to sort it.  

* Vector

  > Merge Sort.

* Single Linked List

  > Merge Sort.

* Double Linked List

  > Merge Sort.

* Sorted Vector - already sorted

  > Already sorted.

* Sorted Single Linked List - already sorted

  > Already sorted.

* Sorted Double Linked List - already sorted

  > Already sorted.

* Binary Search Tree 

  > Inorder traversal.

### Worst Case vs. Average Case

There are a few functions whose worse case is very different than the average case. Name at least two of them, and explain why the worse case is so much worse than the average case. 

1. BST Add/Insert

   > If the data are added/ inserted in a sorted order, the tree will degenerate into a linked list which causes O(n).

2. Vector Add Back

   > If the vector runs out of capacity, it will have to copy all existing elements to new array which leads to O(n) operations.

## Empirical Analysis - Speed Comparison

For this section, you will need to have run the speed compare program and generated the output into a CSV file.

### Empirical Results Table

Add a link from this document to the CSV file you generated. The CSV file must have at least 15 different N values, but
often can have a lot more depending on what you ran.  

 [results_100k.csv](results_100k.csv) 

### Analysis

Create *at least three* graphics that each visually explain an aspect of your data related to an operation or data structure. Under each one, explain what the graphic is showing, and what you can conclude from it/what you find interesting about it.

> [!IMPORTANT]
> 
> Make sure you are comparing apples to apples and not apples to oranges when choosing what to put in the same graph. 
> 
> **:x: different data structures *and* different operations**
> 
> - Vector Add Front versus BST Add
> 
> **:white_check_mark: different operations *but* same data structure**
> 
> - BST Add versus Remove, and Search for BST
> 
> **:white_check_mark: different data structures *but* same operation**
> 
> - BST Add versus Add for Sorted Vector, and Sorted Single/Double Linked List
> 
> - Vector Add Front versus Add Front for Single/Double Linked List

> [!TIP]
> 
> To create the graphics you can use a third party program like Microsoft Excel or Google Sheets. (Completely optional if you want extra coding: you can use python libraries such as matplotlib, seaborn, or plotly)
> 
> Make sure you can see the image embedded in the Report.md using [image markdown] when you upload it to github, and get help if it doesn't show! 

#### Graphic 1 BSTAdd/ BSTSearch/ BSTRemove

![image-20251112005056499](./g1.png)

> BST search, add, and remove operations all exhibit O(nlgn) growth. However, the time taken for the remove operation is greater than that for search, which is greater than that for add. This is because the actual number of times each operation is performed differs, but this variation is omitted when calculating Big O.

#### Graphic 2 SortedVectorAdd/ LinkedListAdd/ BSTAss

![image-20251112005355785](./g2.png)

> BSTAdd exhibits logarithmic growth, with significantly lower time complexity than LinkedList and SortedVector. LinkedList and SortedVector both grow approximately linearly. In later stages, SortedVector outperforms LinkedList.

#### Graphic 3 VectorGet/ Linked ListGet

![image-20251112005552068](g3.png)

> The time complexity of VectorGet is constant-order, appearing almost as a flat line. In contrast, LinkedList accesses are significantly more numerous than Vector's, exhibiting substantial fluctuations. Since accessing requires traversing all preceding nodes, whether the get operation targets a point near or far from the list's end greatly impacts the number of operations required.

## Critical Thought

### Data Evaluation

Answer the questions below. Make sure to answer each question fully, and explain your reasoning. Indent your answers immediately below the question, for it to line up with the bullet point.

For example:

```markdown
1. What is the most surprising result from the data? Why is it surprising?
   Answer here
```

1. What is the most surprising result from the data? Why is it surprising?

   > The most surprising result in the data is that LinkedList Add is slower than SortedVector Add. Intuitively, modifying pointers should be faster than moving elements within an array.

2. What data structure is the fast at adding elements (sorted)? Why do you think that is?

   > BST. The insertion complexity of BST is logarithmic.


3. What data structure is the fastest at removing elements (sorted)? Why do you think that is?

   > BSTs are the fastest at deleting elements. Due to the unique tree structure of BSTs, they can quickly locate the element to be deleted without traversing preceding elements.

4. What data structure is the fastest at searching? Why do you think that is?

   > SortedVector is the fastest for searching. Both it and BST search have logarithmic time complexity, but experimental results show that SortedVector is faster.

5. What data structure is the fastest for adding elements to the front? Why do you think that is?

   > LinkedList. Because a LinkedList only needs to add one node and adjust one pointer to complete the add front operation.

6. What data structure is the fastest for adding elements to the back? Why do you think that is?

   > LinkedList. Similar to the add front operation, adding to the end of a LinkedList also requires only a single operation. While this is also O(1) for a vector, the vector may occasionally trigger a resizing operation.

7. What data structure is the fastest for removing elements from the front? Why do you think that is?

   > LinkedList. The same pattern applies as with front insertion. LinkedList front deletion is O(1) — it simply updates the head pointer to the next and removes the old head node.

8. What data structure is the fastest for removing elements from the back? Why do you think that is?

   > Doubly linked list. Its principle is identical to removing elements from the front in a linked list.

### Deeper Thinking

#### Double Linked List vs Single Linked List

1. If you wrote your linked list as a single linked list, removing from the back was expensive. If you wrote it as a double linked list, removing from the back was cheap. Why do you think that is?

   > Each node in a doubly linked list has two pointers: prev and next, forming bidirectional connections. This is equivalent to a single linked list that can be traversed backward, making it easy to operate from the tail toward the head.

2. When running most functions, at least ~30% of the tests were worse case scenarios. Why do you think that is? 

   > Only under certain worst-case scenarios can the potential occurrences of real-world data be reflected.

3. What was done in the code to encourage that? 

   > The code uses the `build_sample_indexes()` function with `SAMPLE_SPLIT = 0.7` to ensure that only 70% of the samples are sure to be elements already present in the data structure. While others might have the chance of being outside of the index.

4. How did this particularly influence the linked list searches?

   > The time required for linked list searches fluctuates significantly rather than tending toward a linear pattern.

#### Test Bias

1. The tests were inherently biased towards the BST to perform better due the setup of the experiment. Explain why this is the case.  (hint: think about the randomization of the data, and the worst case scenario for BST).

2. What would generate the worst case scenery for a BST?

   > The input data is ordered or nearly ordered.

3. Researching beyond the module, how would one fix a BST so the worst case scenario matches (or at least i closer to) the average case.[^1^]

## Scenario

Fill out the table below. This is a common technical interview topic!

| Structure          | Good to use when                                                                 | Bad to use when                                                                  |
| ------------------ | -------------------------------------------------------------------------------- | -------------------------------------------------------------------------------- |
| Vector             |                                                                                  |                                                                                  |
| Linked List        | Good for stacks with frequent front only access                                  |                                                                                  |
| Sorted Vector      | When values coming in are already mostly sorted and we need quick search access. | When space is limited and the dataset is extremely large causing memory to swap. |
| Sorted Linked List |                                                                                  |                                                                                  |
| BST                |                                                                                  | data is presorted                                                                |

## Conclusion

Summarize your findings. Where there any surprises?  What did you end up learning by comparing speeds?

## Technical Interview Practice Questions

For both these questions, are you are free to use what you did as the last section on the team activities/answered as a group, or you can use a different question.

1. Select one technical interview question (this module or previous) from the [technical interview list](https://github.com/CS5008-khoury/Resources/blob/main/TechInterviewQuestions.md) below and answer it in a few sentences. You can use any resource you like to answer the question.

2. Select one coding question (this module or previous) from the [coding practice repository](https://github.com/CS5008-khoury/Resources/blob/main/LeetCodePractice.md) and include a c file with that code with your submission. Make sure to add comments on what you learned, and if you compared your solution with others. 

## References

Add your references here. A good reference includes an inline citation, such as [1] , and then down in your references section, you include the full details of the reference. Computer Science research often uses [IEEE] or [ACM Reference format].

[1] Reference info, date, etc.

[^1^]: Implementing a BST with a self-balancing algorithm, such as AVL or Red-Black Trees is a great research paper topic!

<!-- links moved to bottom for easier reading in plain text (btw, this a comment that doesn't show in the webpage generated-->

[image markdown]: https://docs.github.com/en/get-started/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax#images

[ACM Reference Format]: https://www.acm.org/publications/authors/reference-formatting
[IEEE]: https://www.ieee.org/content/dam/ieee-org/ieee/web/org/conferences/style_references_manual.pdf
