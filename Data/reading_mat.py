import scipy.io as sio

# Load the .mat file
mat_file = sio.loadmat('./Data/punch1.mat')

# Extract the array from the file
mat_array = mat_file['region2']

print(mat_array)