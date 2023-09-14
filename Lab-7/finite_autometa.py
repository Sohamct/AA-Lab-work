#Finite Autometa:
def string_matcher(pattern, text):
    # Create the DFA transition table
    transition_table = [         
        {'a': 1, 'b': 0, 'c': 0}, 
        {'a': 1, 'b': 2, 'c': 0}, 
        {'a': 3, 'b': 0, 'c': 0}, 
        {'a': 1, 'b': 4, 'c': 0}, 
        {'a': 5, 'b': 0, 'c': 0}, 
        {'a': 1, 'b': 4, 'c': 6}, 
        {'a': 7, 'b': 0, 'c': 0}, 
        {'a': 1, 'b': 2, 'c': 0}, 
    ]

    # Set the accepting state
    accepting_state = 7

    state = 0  # Start at the initial state
    for char in text:
        if char in transition_table[state]:
            state = transition_table[state][char]
        else:
            state = 0  

        if state == accepting_state:
            return True  

    return False  


pattern = "ababaca"
text = "abacbacababababacaaca"
if string_matcher(pattern, text):
    print("Pattern found in the text.")
else:
    print("Pattern not found in the text.")
