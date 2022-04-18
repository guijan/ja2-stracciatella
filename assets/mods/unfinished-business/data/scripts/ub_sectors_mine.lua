RegisterListener("BeforeStructureDamaged", "handle_mine_entrance_damage")

MAP_ROW_I = 9


function init_mine_entrance_sector()
    extra_game_state.mine_entrance_collapsed = false
end

function handle_mine_entrance_damage(x, y, z, grid_no, pCurrent, dist, skipDamage)
    if y == MAP_ROW_I and x == 13 and z == 0 and grid_no == 12421 then
        replace_mine_entrance()
    end
end

function replace_mine_entrance()
    if extra_game_state.mine_entrance_collapsed then
       return
    end
    extra_game_state.mine_entrance_collapsed = true
    log.info("mine entrance collapsed")
    RemoveExitGridFromWorld(12422)
    RemoveExitGridFromWorld(12423)

    --TODO: update collapsed entrance graphics
    --[[
            UINT16                                                                  usTileIndex;
            UINT16 usGridNo=12745;

            //Make sure wed ont blow things up twice
            if( gJa25SaveStruct.fBiggensUsedDetonator )
                    return;

            //Remeber that biggens detonated the explosives
            gJa25SaveStruct.fBiggensUsedDetonator = TRUE;

            // Turn on permenant changes....
            ApplyMapChangesToMapTempFile( TRUE );

            // Remove it!
            // Get index for it...
            GetTileIndexFromTypeSubIndex( FIRSTOSTRUCT, (INT8)( 1 ), &usTileIndex );

            AddStructToHead( usGridNo, usTileIndex );

            //remove the exit grid from the world
            RemoveExitGridFromWorld( 12422 );
            RemoveExitGridFromWorld( 12423 );
            AddRemoveExitGridToUnloadedMapTempFile( 12422, 13, MAP_ROW_I, 0 );
            AddRemoveExitGridToUnloadedMapTempFile( 12423, 13, MAP_ROW_I, 0 );

            gpWorldLevelData[ usGridNo ].uiFlags |= MAPELEMENT_REVEALED;

                    // Re-render the world!
            gTacticalStatus.uiFlags |= NOHIDE_REDUNDENCY;

            // FOR THE NEXT RENDER LOOP, RE-EVALUATE REDUNDENT TILES
            InvalidateWorldRedundency( );
            SetRenderFlags(RENDER_FLAG_FULL);

            // Redo movement costs....
            RecompileLocalMovementCostsFromRadius( usGridNo, 5 );
            //
            // Apply changes to the underground mine
            //

            //Remove the old tunnel pieces first

            //First half of entrance
            usGridNo = 13057;

            // Get index for it...
            GetTileIndexFromTypeSubIndex( FIRSTDECORATIONS, (INT8)( 1 ), &usTileIndex );

            RemoveStructFromUnLoadedMapTempFile( usGridNo, usTileIndex, 13, MAP_ROW_I, 1 );

            // Get index for it...
            GetTileIndexFromTypeSubIndex( FIRSTDECORATIONS, (INT8)( 5 ), &usTileIndex );

            //Apply changes
            AddStructToUnLoadedMapTempFile( usGridNo, usTileIndex, 13, MAP_ROW_I, 1 );

            // 2nd half of entrance
            usGridNo = 12897;

            // Get index for it...
            GetTileIndexFromTypeSubIndex( FIRSTDECORATIONS, (INT8)( 2 ), &usTileIndex );

            RemoveStructFromUnLoadedMapTempFile( usGridNo, usTileIndex, 13, MAP_ROW_I, 1 );

            // Get index for it...
            GetTileIndexFromTypeSubIndex( FIRSTDECORATIONS, (INT8)( 6 ), &usTileIndex );

            //Apply changes
            AddStructToUnLoadedMapTempFile( usGridNo, usTileIndex, 13, MAP_ROW_I, 1 );

            //Remove the exit grid
            AddRemoveExitGridToUnloadedMapTempFile( usGridNo, 13, MAP_ROW_I, 1 );

            // Turn off permenant changes....
            ApplyMapChangesToMapTempFile( FALSE );






    --]]
end