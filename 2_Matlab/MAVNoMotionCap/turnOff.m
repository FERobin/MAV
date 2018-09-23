function turnOff(s)
    motor_speed = ones(4,1)*(80);
    motorString = sprintf('%dz', motor_speed);
    fwrite(s, ['m' motorString]);
end