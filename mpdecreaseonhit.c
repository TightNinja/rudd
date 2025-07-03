void main()
{
    void self = getlocalvar("self");
    void attacker = getlocalvar("attacker");
    int damage = getlocalvar("damage");
    int mp = getentityproperty(self, "mp");
    int health = getentityproperty(self, "health");
    
    // Get player and attacker names
    void selfname = getentityproperty(self, "name");
    void attackername = "Unknown";
    if(attacker) {
        attackername = getentityproperty(attacker, "name");
    }
    
    // Determine event type - simplified approach
    int animation = getentityproperty(self, "animation");
    int frame = getentityproperty(self, "animpos");
    
    void event_type = "HIT";
    // Check if current animation is a block animation
    if(animation == openborconstant("ANI_BLOCK")) {
        event_type = "BLOCK";
    }
    
    // Store MP before change
    int mp_before = mp;
    
    // Reduce MP
    if(mp > 0) {
        changeentityproperty(self, "mp", mp - 1);
    }
    
    int mp_after = getentityproperty(self, "mp");
    int mp_change = mp_after - mp_before;
    
    // Create TSV formatted output with current timestamp
    void tsv_line = "2025-06-27 20:07:00\t" + 
                    event_type + "\t" + 
                    selfname + "\t" + 
                    attackername + "\t" + 
                    damage + "\t" + 
                    health + "\t" + 
                    mp_before + "\t" + 
                    mp_after + "\t" + 
                    mp_change + "\t" + 
                    animation + "\t" + 
                    frame;
    
    // Write to log file (append mode)
    openfilestream("mpdebugg.tsv", 1);
    savefilestream(tsv_line);
    closefilestream();
    
    // Also log to console
    log("MP_DEBUG: " + event_type + " - " + selfname + " vs " + attackername + " | Damage: " + damage + " | MP: " + mp_before + "->" + mp_after);
}