namespace targets {
// TODO: Insert the code for the alien class here
class Alien {
    private:
        int health { 3 };

    public:
        int x_coordinate{};
        int y_coordinate{};

        Alien(int x, int y)
            : x_coordinate { x }
            , y_coordinate { y }
            {}

        int get_health() {
            return health;
        }

        bool hit() {
            return (health > 0) ? --health : 0;
        }

        bool is_alive() {
            return health;
        }

        bool teleport(int x_new, int y_new) {
            x_coordinate = x_new;
            y_coordinate = y_new;
            return true;
        }

        bool collision_detection(Alien other_alien) {
            if (x_coordinate == other_alien.x_coordinate 
                && y_coordinate == other_alien.y_coordinate) {
                return true;
            }
            return false;
        }
};

}  // namespace targets
