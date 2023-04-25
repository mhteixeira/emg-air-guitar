% Specify the file name and path
filename = './punch.txt';
disp(filename)
% Open the text file
fid = fopen(filename, 'r');

% Check if the file was opened successfully
if fid == -1
    error('Unable to open file: %s', filename);
end

% Read in the lines of the text file
C = textscan(fid, '%s -> %s');

% Close the file
fclose(fid);

% Extract the values after "->" and convert to numerical format
values = cell2mat(cellfun(@(x) str2double(x), C{2}, 'UniformOutput', false));

% Plot the values
plot(values);
