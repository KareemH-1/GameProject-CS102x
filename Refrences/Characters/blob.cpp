void moveBlob( int& row , int& col , int startCol , int endCol , int &direction , int & isJumping){
    if (col <= startCol) {
        direction = 1; 
    } else if (col >= endCol) {
        direction = 2; 
    }

    if (direction == 1) {
        if(!isJumping){
            row--;
            col++;
            isJumping =1;
        } else {
            row++;
            col++;
            isJumping =0;
        }
        
    } else if (direction == 2) {
        if(!isJumping){
            row--;
            col--;
            isJumping =1;
        } else {
            row++;
            col--;
            isJumping =0;
        }
        
    }
}