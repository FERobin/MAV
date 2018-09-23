function turnOn(s, channel)
    motor_speed = ones(4,1)*(80);
    motor_speed(channel) = 89;
    motorString = sprintf('%dz', motor_speed);
    fwrite(s, ['m' motorString]);
end