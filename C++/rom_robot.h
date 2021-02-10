#ifndef ROM_ROBOTICS
#define ROM_ROBOTICS

namespace rom_robot
{
    class fk
    {
        public:
            float pi = 3.1415;
            int cpr = 0;
            int total_encoder_ticks = 0;
            float wheel_diameter = 0;
            float cpr_diameter_constant = 0;

            fk(cpr,wheel_diameter)
            {
                cpr_diameter_constant = (pi*wheel_diameter) / cpr;
            }

            
        private:

            float get_wheel_travelled(int total_encoder_ticks)
            {
                return (total_encoder_ticks*cpr_diameter_constant); 
            }

            float get_average_travelled()
            {
                float right_travelled = get_wheel_travelled(int right);
                float left_travelled  = get_wheel_travelled(int left );
                float average  = (right_travelled + left_travelled) / 2.0;
                return average;
            }


    };



} // end rom_robot

#endif