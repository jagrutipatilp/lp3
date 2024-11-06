class Node:
    def __init__(self, char, freq):
        self.char = char  # Character (None for internal nodes)
        self.freq = freq  # Frequency of the character
        self.left = None  # Left child (for internal nodes)
        self.right = None  # Right child (for internal nodes)


def build_huffman_tree(freq_map):
    # Step 1: Create leaf nodes from the frequency map
    nodes = []
    for char, freq in freq_map.items():
        nodes.append(Node(char, freq))

    # Step 2: Build the Huffman tree by merging nodes
    while len(nodes) > 1:
        # Sort the nodes based on frequency (ascending order)
        nodes.sort(key=lambda node: node.freq)

        # Take two nodes with the smallest frequencies
        left = nodes.pop(0)
        right = nodes.pop(0)

        # Merge two nodes into one
        merged = Node(None, left.freq + right.freq)  # New internal node with combined frequency
        merged.left = left
        merged.right = right

        # Add the merged node back to the list of nodes
        nodes.append(merged)

    # The last remaining node is the root of the Huffman tree
    return nodes[0]  # Return the root of the Huffman tree

def generate_codes(node, current_code, codes):
    if node is None:
        return

    if node.char is not None:  # If it's a leaf node
        codes[node.char] = current_code

    # Traverse left and right subtrees
    generate_codes(node.left, current_code + "0", codes)
    generate_codes(node.right, current_code + "1", codes)

def encode(input_string, huffman_codes):
    encoded_str = ''
    for char in input_string:
        encoded_str += huffman_codes[char]
    return encoded_str

def decode(encoded_str, root):
    decoded_str = ''
    current_node = root
    for bit in encoded_str:
        if bit == '0':
            current_node = current_node.left
        else:
            current_node = current_node.right

        if current_node.char is not None:  # Leaf node
            decoded_str += current_node.char
            current_node = root  # Reset to root for the next character

    return decoded_str

# Example usage:
input_string = str(input("enter string: "))

# Step 1: Calculate frequency of each character
freq_map = {}
for char in input_string:
    if char in freq_map:
        freq_map[char] += 1
    else:
        freq_map[char] = 1

# Step 2: Build Huffman Tree
root = build_huffman_tree(freq_map)

# Step 3: Generate Huffman Codes
huffman_codes = {}
generate_codes(root, "", huffman_codes)

# Step 4: Encode the input string
encoded_str = encode(input_string, huffman_codes)

# Step 5: Decode the encoded string
decoded_str = decode(encoded_str, root)
print("\nHuffman Codes:", huffman_codes)
print("Encoded String:", encoded_str)
print("Decoded String:", decoded_str)
