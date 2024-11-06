# Define the function and its derivative
def f(x):
    return (x + 3) ** 2

def f_prime(x):
    return 2 * (x + 3)

# Gradient Descent Algorithm
def gradient_descent(starting_point, learning_rate, iterations):
    x = starting_point
    for _ in range(iterations):
        x = x - learning_rate * f_prime(x)
        
    return x

# Parameters
starting_point = 2
learning_rate = 0.1
iterations = 100

# Run gradient descent
minima = gradient_descent(starting_point, learning_rate, iterations)
print(f"Local minima found at x: {minima}, f(x): {f(minima)}")
