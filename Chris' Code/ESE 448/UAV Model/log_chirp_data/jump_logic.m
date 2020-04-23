function [h, h_past] = jump_logic(h, h_past)

%difference to trigger bad measurement
c = 1;

%mean of past X measurements of h
past_avg = mean(h_past);

if (abs(h-past_avg) > c)
    h = h_past(1);
else
    h = h;
end

%updates past measurements of h (feeds back into 
h_past = [h h_past(1:end-1)];