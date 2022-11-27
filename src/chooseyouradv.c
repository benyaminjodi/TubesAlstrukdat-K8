#include "boolean.h"
#include <stdio.h>

#define Nil NULL

#include<stdio.h>
 
typedef struct node {
    char* data;
    struct node* left;
    struct node* right;
} node;

boolean isLeaf(node base) {
    if ((base.left == Nil) && (base.right == Nil)){
        return(true);
    }
    else{
        return(false);
    }

}

int result=0;

int recursive(node* base){
    printf("%s", (*base).data);
    if (isLeaf(*base)==true)
    {
        return 1;
    }
    else
    {
        int answer;
        boolean isValid;
        isValid = false;
        //Inputting answwer from user
        while (isValid!=true)
        {
            printf("Type whether you choose yes or no (0 for yes/1 for no)\n");
            scanf("%d", &answer);
            if (answer==0)
            {
                isValid=true;
            }
            if (answer==1)
            {
                isValid=true;
            }
        }
        //Decision branching
        if (answer==0)
        {
            result=result+recursive((*base).left)+1;
            return (result);
        }
        if (answer==1)
        {
            result=result+recursive((*base).right)+1;
            return (result);
        }
    }
}

void playchooseyouradv(){
    //-----------------------------------------------------------------//
    int scoreCount=0;
    node route1, route2, route3, route10, route20;
    //Inserting NIL to leafs
    route10.left=Nil;
    route10.right=Nil;
    route20.left=Nil;
    route20.right=Nil;
    route3.left=Nil;
    route3.right=Nil;
    //Inserting child address to nodes
    route1.left=&route2;
    route1.right=&route10;
    route2.left=&route20;
    route2.right=&route3;

    //Text contained here//
    route1.data="\nYou find yourself standing in a beautiful garden. It teems with all the birds of the air, and all of the creatures of the Earth, and every good thing that grows.\nAs you explore, you feel an incredible sense of peace and rightness, as if the garden had been created just for you.\nThis is the place you belong. Still, you are restless and lonely. You begin to explore your surroundings.\nAt the western edge of the garden, there is a gate. \n\nDo you walk through?\n\n";
    route10.data="\nYou wish to see more of the garden before you leave its bounds.\nSoon, you are glad you have chosen as you did, for you find the perfect companion for all your days and nights.\nYou come to believe you have found a new Eden, as well.\nIt seems impossible for a place so perfect to be other than Paradise.\nWhen they are born, you name your children Kane and Abelle.\n\n";
    route2.data="\nGates, like books, are meant to be opened, and you would never be truly content if you did not know what lay on the other side.\nYou pass through the gate and enter into a dark forest.\nYou hesitate for a moment, look back, but the forest stretches behind you as if the garden had never been.\n\nYou continue on.\n\nShadows deepen. An owl calls. Something cries out at a distance and is silenced.\nYou grow chilled, and your feet develop a talent for finding uneven spots of ground, tree roots, and rocks.\nAfter the third time you fall, you lean against the very tree whose roots last tangled your feet.\nThe bark prickles and rubs against your back, but it is a welcome distraction from your bruised knees and skinned palms.\nYour bones are weary and your muscles ache.\nYou crave sleep. A brief rest to fortify yourself for your journey. \n\nDo you close your eyes?\n\n";
    route20.data="\nYou close your eyes, and drift into sleep. When you awaken, you are in your own bed.\nThe previous events were a dream, which has already begun to fade.\nYou spend the rest of your life trying to return to the winding path in the dark forest.\n\nYou never will.\n\n";
    route3.data="\nYou scrub your hands across your eyes and push yourself back to your feet.\nThe path takes you on a short, downhill curve, and winds around to the door of an inn.\nThe Quill and Ink, reads the sign over the door. You smile, and enter.\nInside, there is warmth, the hearty scent of food, and a group of people singing songs both off-key and bawdy.\nYou slide seamlessly into the small community, and feel refreshed after you have shared a meal and stood a round of drinks.\nEventually, you notice the singing has died down, replaced by a rapt silence. \nThere is a knot of people wound tight around the fire, telling stories.\nAt first, you simply listen, but then you are asked to tell a tale of your own.\nIt is the tale, not the coin, that will pay your shelter for the night.\n\nDo you tell a story?\n\n";
    scoreCount = recursive(&route1);
    printf("%d", scoreCount);
}