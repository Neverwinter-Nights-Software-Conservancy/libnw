<?xml version="1.0" encoding="US-ASCII"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:nwn="http://www.bioware.com/" version="1.0">

<-- This works reasonably with BICs as well as UTCs -->

  <xsl:variable name="FName" select="/nwn:UTC/nwn:OBJECT[@NAME='FirstName']/nwn:LOCSTRS/nwn:LOCSTR[@LANG='0']"/>
  <xsl:variable name="LName" select="/nwn:UTC/nwn:OBJECT[@NAME='LastName']/nwn:LOCSTRS/nwn:LOCSTR[@LANG='0']"/>
  <xsl:variable name="Law" select="/nwn:UTC/nwn:OBJECT[@NAME='LawfulChaotic']/nwn:SCALAR/attribute::VALUE"/>
  <xsl:variable name="Good" select="/nwn:UTC/nwn:OBJECT[@NAME='GoodEvil']/nwn:SCALAR/attribute::VALUE"/>
  <xsl:variable name="Phenotype" select="/nwn:UTC/nwn:OBJECT[@NAME='Phenotype']/nwn:SCALAR/attribute::VALUE"/>
  <xsl:variable name="Gender" select="/nwn:UTC/nwn:OBJECT[@NAME='Gender']/nwn:SCALAR/attribute::VALUE"/>
  <xsl:variable name="Race" select="/nwn:UTC/nwn:OBJECT[@NAME='Race']/nwn:SCALAR/attribute::VALUE"/>
  <xsl:variable name="Class1" select="/nwn:UTC/nwn:OBJECT[@NAME='ClassList']/nwn:LIST/nwn:LISTITEM[position()=1]/nwn:OBJECT[@NAME='Class']/nwn:SCALAR/attribute::VALUE"/>
  <xsl:variable name="ClassLevel1" select="/nwn:UTC/nwn:OBJECT[@NAME='ClassList']/nwn:LIST/nwn:LISTITEM[position()=1]/nwn:OBJECT[@NAME='ClassLevel']/nwn:SCALAR/attribute::VALUE"/>
  <xsl:variable name="Class2" select="/nwn:UTC/nwn:OBJECT[@NAME='ClassList']/nwn:LIST/nwn:LISTITEM[position()=2]/nwn:OBJECT[@NAME='Class']/nwn:SCALAR/attribute::VALUE"/>
  <xsl:variable name="ClassLevel2" select="/nwn:UTC/nwn:OBJECT[@NAME='ClassList']/nwn:LIST/nwn:LISTITEM[position()=2]/nwn:OBJECT[@NAME='ClassLevel']/nwn:SCALAR/attribute::VALUE"/>
  <xsl:variable name="Class3" select="/nwn:UTC/nwn:OBJECT[@NAME='ClassList']/nwn:LIST/nwn:LISTITEM[position()=3]/nwn:OBJECT[@NAME='Class']/nwn:SCALAR/attribute::VALUE"/>
  <xsl:variable name="ClassLevel3" select="/nwn:UTC/nwn:OBJECT[@NAME='ClassList']/nwn:LIST/nwn:LISTITEM[position()=3]/nwn:OBJECT[@NAME='ClassLevel']/nwn:SCALAR/attribute::VALUE"/>
  <xsl:variable name="Str" select="/nwn:UTC/nwn:OBJECT[@NAME='Str']/nwn:SCALAR/attribute::VALUE"/>
  <xsl:variable name="Dex" select="/nwn:UTC/nwn:OBJECT[@NAME='Dex']/nwn:SCALAR/attribute::VALUE"/>
  <xsl:variable name="Con" select="/nwn:UTC/nwn:OBJECT[@NAME='Con']/nwn:SCALAR/attribute::VALUE"/>
  <xsl:variable name="Int" select="/nwn:UTC/nwn:OBJECT[@NAME='Int']/nwn:SCALAR/attribute::VALUE"/>
  <xsl:variable name="Wis" select="/nwn:UTC/nwn:OBJECT[@NAME='Wis']/nwn:SCALAR/attribute::VALUE"/>
  <xsl:variable name="Cha" select="/nwn:UTC/nwn:OBJECT[@NAME='Cha']/nwn:SCALAR/attribute::VALUE"/>
  <xsl:variable name="HP" select="/nwn:UTC/nwn:OBJECT[@NAME='HitPoints']/nwn:SCALAR/attribute::VALUE"/>
  <xsl:variable name="CHP" select="/nwn:UTC/nwn:OBJECT[@NAME='CurrentHitPoints']/nwn:SCALAR/attribute::VALUE"/>
  <xsl:variable name="NAC" select="/nwn:UTC/nwn:OBJECT[@NAME='NaturalAC']/nwn:SCALAR/attribute::VALUE"/>
  <xsl:variable name="CR" select="/nwn:UTC/nwn:OBJECT[@NAME='ChallengeRating']/nwn:SCALAR/attribute::VALUE"/>
  <xsl:variable name="CRA" select="/nwn:UTC/nwn:OBJECT[@NAME='CRAdjust']/nwn:SCALAR/attribute::VALUE"/>
  <xsl:variable name="ReflST" select="/nwn:UTC/nwn:OBJECT[@NAME='RefSaveThrow']/nwn:SCALAR/attribute::VALUE"/>
  <xsl:variable name="FortST" select="/nwn:UTC/nwn:OBJECT[@NAME='FortSaveThrow']/nwn:SCALAR/attribute::VALUE"/>
  <xsl:variable name="WillST" select="/nwn:UTC/nwn:OBJECT[@NAME='WillSaveThrow']/nwn:SCALAR/attribute::VALUE"/>
  <xsl:variable name="ReflBonus" select="/nwn:UTC/nwn:OBJECT[@NAME='refbonus']/nwn:SCALAR/attribute::VALUE"/>
  <xsl:variable name="FortBonus" select="/nwn:UTC/nwn:OBJECT[@NAME='fortbonus']/nwn:SCALAR/attribute::VALUE"/>
  <xsl:variable name="WillBonus" select="/nwn:UTC/nwn:OBJECT[@NAME='willbonus']/nwn:SCALAR/attribute::VALUE"/>
  <xsl:variable name="WalkRate" select="/nwn:UTC/nwn:OBJECT[@NAME='WalkRate']/nwn:SCALAR/attribute::VALUE"/>
  <xsl:variable name="PerceptionRange" select="/nwn:UTC/nwn:OBJECT[@NAME='PerceptionRange']/nwn:SCALAR/attribute::VALUE"/>
  <xsl:variable name="ScriptHeartbeat" select="/nwn:UTC/nwn:OBJECT[@NAME='ScriptHeartbeat']/nwn:SCALAR/attribute::VALUE"/>
  <xsl:variable name="ScriptOnNotice" select="/nwn:UTC/nwn:OBJECT[@NAME='ScriptOnNotice']/nwn:SCALAR/attribute::VALUE"/>
  <xsl:variable name="ScriptSpellAt" select="/nwn:UTC/nwn:OBJECT[@NAME='ScriptSpellAt']/nwn:SCALAR/attribute::VALUE"/>
  <xsl:variable name="ScriptAttacked" select="/nwn:UTC/nwn:OBJECT[@NAME='ScriptAttacked']/nwn:SCALAR/attribute::VALUE"/>
  <xsl:variable name="ScriptDamaged" select="/nwn:UTC/nwn:OBJECT[@NAME='ScriptDamaged']/nwn:SCALAR/attribute::VALUE"/>
  <xsl:variable name="ScriptDisturbed" select="/nwn:UTC/nwn:OBJECT[@NAME='ScriptDisturbed']/nwn:SCALAR/attribute::VALUE"/>
  <xsl:variable name="ScriptEndRound" select="/nwn:UTC/nwn:OBJECT[@NAME='ScriptEndRound']/nwn:SCALAR/attribute::VALUE"/>
  <xsl:variable name="ScriptDialogue" select="/nwn:UTC/nwn:OBJECT[@NAME='ScriptDialogue']/nwn:SCALAR/attribute::VALUE"/>
  <xsl:variable name="ScriptSpawn" select="/nwn:UTC/nwn:OBJECT[@NAME='ScriptSpawn']/nwn:SCALAR/attribute::VALUE"/>
  <xsl:variable name="ScriptRested" select="/nwn:UTC/nwn:OBJECT[@NAME='ScriptRested']/nwn:SCALAR/attribute::VALUE"/>
  <xsl:variable name="ScriptDeath" select="/nwn:UTC/nwn:OBJECT[@NAME='ScriptDeath']/nwn:SCALAR/attribute::VALUE"/>
  <xsl:variable name="ScriptUserDefine" select="/nwn:UTC/nwn:OBJECT[@NAME='ScriptUserDefine']/nwn:SCALAR/attribute::VALUE"/>
  <xsl:variable name="ScriptOnBlocked" select="/nwn:UTC/nwn:OBJECT[@NAME='ScriptOnBlocked']/nwn:SCALAR/attribute::VALUE"/>

  <xsl:template match="/">
    <html>
      <body>
        <xsl:apply-templates/>
      </body>
    </html>
  </xsl:template>
  <xsl:template match="/nwn:UTC">
    <h1>
      <center>
        <xsl:text>Neverwinter Nights Character Data</xsl:text>
      </center>
    </h1>
    <h1>
      <center>
        <xsl:value-of select="$FName"/>
        <xsl:text> </xsl:text>
        <xsl:value-of select="$LName"/>
      </center>
	  <center>
		<xsl:call-template name="nwn:AlignmentNumsToName">
		  <xsl:with-param name="Law" select="$Law"/>
		  <xsl:with-param name="Good" select="$Good"/>
		</xsl:call-template>
	  </center>
	  <center>
        <xsl:call-template name="nwn:PhenotypeNumToName">
          <xsl:with-param name="val" select="$Phenotype"/>
        </xsl:call-template>
        <xsl:text> </xsl:text>
        <xsl:call-template name="nwn:GenderNumToName">
          <xsl:with-param name="val" select="$Gender"/>
        </xsl:call-template>
        <xsl:text> </xsl:text>
        <xsl:call-template name="nwn:RaceNumToName">
          <xsl:with-param name="val" select="$Race"/>
        </xsl:call-template>
      </center>
	  <center>
	    <xsl:call-template name="nwn:ClassNumToName">
		  <xsl:with-param name="val" select="$Class1"/>
		</xsl:call-template>
		<xsl:text> </xsl:text>
		<xsl:value-of select="$ClassLevel1"/>
		<xsl:if test="string-length($Class2) &gt; 0">
		  <xsl:text> / </xsl:text>
		  <xsl:call-template name="nwn:ClassNumToName">
		    <xsl:with-param name="val" select="$Class2"/>
		  </xsl:call-template>
		  <xsl:text> </xsl:text>
		  <xsl:value-of select="$ClassLevel2"/>
		  <xsl:if test="string-length($Class3) &gt; 0">
		    <xsl:text> / </xsl:text>
			<xsl:call-template name="nwn:ClassNumToName">
			  <xsl:with-param name="val" select="$Class3"/>
			</xsl:call-template>
			<xsl:text> </xsl:text>
			<xsl:value-of select="$ClassLevel3"/>
		  </xsl:if>
		</xsl:if>
	  </center>
    </h1>
    <table>
      <tr>
        <td>
          <table>
            <tr>
              <th>Attribute</th>
              <th>Value</th>
              <th>Bonus</th>
            </tr>
            <tr>
              <td>Strength</td>
              <td>
                <xsl:value-of select="$Str"/>
              </td>
              <td>
                <xsl:call-template name="nwn:AttToBonus">
                  <xsl:with-param name="val" select="$Str"/>
                </xsl:call-template>
              </td>
            </tr>
            <tr>
              <td>Dexterity</td>
              <td>
                <xsl:value-of select="$Dex"/>
              </td>
              <td>
                <xsl:call-template name="nwn:AttToBonus">
                  <xsl:with-param name="val" select="$Dex"/>
                </xsl:call-template>
              </td>
            </tr>
            <tr>
              <td>Constitution</td>
              <td>
                <xsl:value-of select="$Con"/>
              </td>
              <td>
                <xsl:call-template name="nwn:AttToBonus">
                  <xsl:with-param name="val" select="$Con"/>
                </xsl:call-template>
              </td>
            </tr>
            <tr>
              <td>Intelligence</td>
              <td>
                <xsl:value-of select="$Int"/>
              </td>
              <td>
                <xsl:call-template name="nwn:AttToBonus">
                  <xsl:with-param name="val" select="$Int"/>
                </xsl:call-template>
              </td>
            </tr>
            <tr>
              <td>Wisdom</td>
              <td>
                <xsl:value-of select="$Wis"/>
              </td>
              <td>
                <xsl:call-template name="nwn:AttToBonus">
                  <xsl:with-param name="val" select="$Wis"/>
                </xsl:call-template>
              </td>
            </tr>
            <tr>
              <td>Charisma</td>
              <td>
                <xsl:value-of select="$Cha"/>
              </td>
              <td>
                <xsl:call-template name="nwn:AttToBonus">
                  <xsl:with-param name="val" select="$Cha"/>
                </xsl:call-template>
              </td>
            </tr>
			<tr></tr>
			<tr>
			  <td>Hit Points</td>
			  <td>
			    <xsl:value-of select="$CHP"/>
				<xsl:text> / </xsl:text>
				<xsl:value-of select="$HP"/>
			  </td>
			  <td></td>
			</tr>
			<tr>
			  <td>Natural AC</td>
			  <td>
			    <xsl:value-of select="$NAC"/>
			  </td>
			  <td></td>
			</tr>
			<tr>
			  <td>Challenge Rating</td>
			  <td>
			    <xsl:value-of select="$CR"/>
				<xsl:text> + </xsl:text>
				<xsl:value-of select="$CRA"/>
			  </td>
			  <td></td>
			</tr>
			<tr>
			  <td>Reflex Saving Throw</td>
			  <td>
			    <xsl:value-of select="$ReflST"/>
			  </td>
			  <td>
			    <xsl:value-of select="$ReflBonus"/>
			  </td>
			</tr>
			<tr>
			  <td>Fortitude Saving Throw</td>
			  <td>
			    <xsl:value-of select="$FortST"/>
			  </td>
			  <td>
			    <xsl:value-of select="$FortBonus"/>
			  </td>
			</tr>
			<tr>
			  <td>Will Saving Throw</td>
			  <td>
			    <xsl:value-of select="$WillST"/>
			  </td>
			  <td>
			    <xsl:value-of select="$WillBonus"/>
			  </td>
			</tr>
			<tr>
			  <td>Walk Rate</td>
			  <td>
			    <xsl:value-of select="$WalkRate"/>
			  </td>
			  <td></td>
			</tr>
			<tr>
			  <td>Perception Range</td>
			  <td>
			    <xsl:value-of select="$PerceptionRange"/>
			  </td>
			  <td></td>
			</tr>
          </table>
        </td>
		<td>
		  <table>
		    <tr>
			  <th>Script Type</th>
			  <th>Script RESREF</th>
			</tr>
			<tr>
			  <td>Heartbeat</td>
			  <td>
			    <xsl:value-of select="$ScriptHeartbeat"/>
			  </td>
			</tr>
			<tr>
			  <td>OnNotice</td>
			  <td>
			    <xsl:value-of select="$ScriptOnNotice"/>
			  </td>
			</tr>
			<tr>
			  <td>SpellAt</td>
			  <td>
			    <xsl:value-of select="$ScriptSpellAt"/>
			  </td>
			</tr>
			<tr>
			  <td>Attacked</td>
			  <td>
			    <xsl:value-of select="$ScriptAttacked"/>
			  </td>
			</tr>
			<tr>
			  <td>Damaged</td>
			  <td>
			    <xsl:value-of select="$ScriptDamaged"/>
			  </td>
			</tr>
			<tr>
			  <td>Disturbed</td>
			  <td>
			    <xsl:value-of select="$ScriptDisturbed"/>
			  </td>
			</tr>
			<tr>
			  <td>EndRound</td>
			  <td>
			    <xsl:value-of select="$ScriptEndRound"/>
			  </td>
			</tr>
			<tr>
			  <td>Dialogue</td>
			  <td>
			    <xsl:value-of select="$ScriptDialogue"/>
			  </td>
			</tr>
			<tr>
			  <td>Spawn</td>
			  <td>
			    <xsl:value-of select="$ScriptSpawn"/>
			  </td>
			</tr>
			<tr>
			  <td>Rested</td>
			  <td>
			    <xsl:value-of select="$ScriptRested"/>
			  </td>
			</tr>
			<tr>
			  <td>Death</td>
			  <td>
			    <xsl:value-of select="$ScriptDeath"/>
			  </td>
			</tr>
			<tr>
			  <td>UserDefine</td>
			  <td>
			    <xsl:value-of select="$ScriptUserDefine"/>
			  </td>
			</tr>
			<tr>
			  <td>OnBlocked</td>
			  <td>
			    <xsl:value-of select="$ScriptOnBlocked"/>
			  </td>
			</tr>
		  </table>
		</td>
      </tr>
    </table>
	<xsl:call-template name="nwn:MemorizedSpells"/>
	<xsl:call-template name="nwn:KnownSpells"/>
	<xsl:call-template name="nwn:BodyParts"/>
    <xsl:apply-templates/>
  </xsl:template>

  <xsl:template match="/nwn:UTC/nwn:OBJECT">
    <xsl:choose>
      <xsl:when test="@NAME = 'FirstName'"/>
      <xsl:when test="@NAME = 'LastName'"/>
      <xsl:when test="@NAME = 'LawfulChaotic'"/>
      <xsl:when test="@NAME = 'GoodEvil'"/>
      <xsl:when test="@NAME = 'Phenotype'"/>
      <xsl:when test="@NAME = 'Gender'"/>
      <xsl:when test="@NAME = 'Race'"/>
      <xsl:when test="@NAME = 'Class'"/>
      <xsl:when test="@NAME = 'Str'"/>
      <xsl:when test="@NAME = 'Dex'"/>
      <xsl:when test="@NAME = 'Con'"/>
      <xsl:when test="@NAME = 'Int'"/>
      <xsl:when test="@NAME = 'Wis'"/>
      <xsl:when test="@NAME = 'Cha'"/>
      <xsl:when test="@NAME = 'HitPoints'"/>
      <xsl:when test="@NAME = 'CurrentHitPoints'"/>
      <xsl:when test="@NAME = 'NaturalAC'"/>
      <xsl:when test="@NAME = 'ChallengeRating'"/>
      <xsl:when test="@NAME = 'CRAdjust'"/>
      <xsl:when test="@NAME = 'refbonus'"/>
      <xsl:when test="@NAME = 'fortbonus'"/>
      <xsl:when test="@NAME = 'willbonus'"/>
      <xsl:when test="@NAME = 'WalkRate'"/>
      <xsl:when test="@NAME = 'PerceptionRange'"/>
      <xsl:when test="@NAME = 'ScriptHeartbeat'"/>
      <xsl:when test="@NAME = 'ScriptOnNotice'"/>
      <xsl:when test="@NAME = 'ScriptSpellAt'"/>
      <xsl:when test="@NAME = 'ScriptAttacked'"/>
      <xsl:when test="@NAME = 'ScriptDamaged'"/>
      <xsl:when test="@NAME = 'ScriptDisturbed'"/>
      <xsl:when test="@NAME = 'ScriptEndRound'"/>
      <xsl:when test="@NAME = 'ScriptDialogue'"/>
      <xsl:when test="@NAME = 'ScriptSpawn'"/>
      <xsl:when test="@NAME = 'ScriptRested'"/>
      <xsl:when test="@NAME = 'ScriptDeath'"/>
      <xsl:when test="@NAME = 'ScriptUserDefine'"/>
      <xsl:when test="@NAME = 'ScriptOnBlocked'"/>
      <xsl:when test="@NAME = 'ArmorPart_RFoot'"/>
      <xsl:when test="@NAME = 'BodyPart_LFoot'"/>
      <xsl:when test="@NAME = 'BodyPart_RShin'"/>
      <xsl:when test="@NAME = 'BodyPart_LShin'"/>
      <xsl:when test="@NAME = 'BodyPart_RThigh'"/>
      <xsl:when test="@NAME = 'BodyPart_LThigh'"/>
      <xsl:when test="@NAME = 'BodyPart_Pelvis'"/>
      <xsl:when test="@NAME = 'BodyPart_Torso'"/>
      <xsl:when test="@NAME = 'BodyPart_Belt'"/>
      <xsl:when test="@NAME = 'BodyPart_Neck'"/>
      <xsl:when test="@NAME = 'BodyPart_RFArm'"/>
      <xsl:when test="@NAME = 'BodyPart_LFArm'"/>
      <xsl:when test="@NAME = 'BodyPart_RBicep'"/>
      <xsl:when test="@NAME = 'BodyPart_LBicep'"/>
      <xsl:when test="@NAME = 'BodyPart_RShoul'"/>
      <xsl:when test="@NAME = 'BodyPart_LShoul'"/>
      <xsl:when test="@NAME = 'BodyPart_RHand'"/>
      <xsl:when test="@NAME = 'BodyPart_LHand'"/>
      <xsl:when test="@NAME = 'Appearance_Head'"/>
      <xsl:when test="@NAME = 'Color_Skin'"/>
      <xsl:when test="@NAME = 'Color_Hair'"/>
      <xsl:when test="@NAME = 'Color_Tattoo1'"/>
      <xsl:when test="@NAME = 'Color_Tattoo2'"/>
      <xsl:otherwise>
        <h2><xsl:value-of select="@NAME"/></h2>
        <xsl:apply-templates/>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>

  <xsl:template match="/nwn:UTC/nwn:OBJECT/nwn:SCALAR">
    <h3>Type: <xsl:value-of select="@TYPE"/></h3>
    <h3>Value: <xsl:value-of select="@VALUE"/></h3>
    <xsl:apply-templates/>
  </xsl:template>

  <xsl:template match="/nwn:UTC/nwn:OBJECT[@NAME='FeatList']/nwn:LIST">
    <h2>Feat List</h2>
      <xsl:for-each select="nwn:LISTITEM/nwn:OBJECT/nwn:SCALAR">
		<xsl:call-template name="nwn:FeatNumToName">
		  <xsl:with-param name="val" select="@VALUE"/>
		</xsl:call-template>
      </xsl:for-each>
  </xsl:template>

  <xsl:template match="/nwn:UTC/nwn:OBJECT[@NAME='SkillList']/nwn:LIST">
    <h2>Skill List</h2>
    <table>
      <tr>
        <th>Skill</th>
        <th>Ranks</th>
      </tr>
      <xsl:for-each select="nwn:LISTITEM/nwn:OBJECT/nwn:SCALAR">
        <tr>
          <td>
            <xsl:call-template name="nwn:SkillNumToName">
              <xsl:with-param name="val" select="position() - 1"/>
            </xsl:call-template>
          </td>
          <td>
            <xsl:value-of select="@VALUE"/>
          </td>
        </tr>
      </xsl:for-each>
    </table>
  </xsl:template>

  <xsl:template name="nwn:FeatNumToName">
    <xsl:choose>
      <xsl:when test="$val = '0'">Alertness</xsl:when>
      <xsl:when test="$val = '1'">Ambidexterity</xsl:when>
      <xsl:when test="$val = '2'">Armor Proficiency Heavy</xsl:when>
      <xsl:when test="$val = '3'">Armor Proficiency Light</xsl:when>
      <xsl:when test="$val = '4'">Armor Proficiency Medium</xsl:when>
      <xsl:when test="$val = '5'">Called Shot</xsl:when>
      <xsl:when test="$val = '6'">Cleave</xsl:when>
      <xsl:when test="$val = '7'">Combat Casting</xsl:when>
      <xsl:when test="$val = '8'">Deflect Arrows</xsl:when>
      <xsl:when test="$val = '9'">Disarm</xsl:when>
      <xsl:when test="$val = '10'">Dodge</xsl:when>
      <xsl:when test="$val = '11'">Empower</xsl:when>
      <xsl:when test="$val = '12'">Extend Spell</xsl:when>
      <xsl:when test="$val = '13'">Extra Turn</xsl:when>
      <xsl:when test="$val = '14'">Great Fortitude</xsl:when>
      <xsl:when test="$val = '15'">Improved Critical Club</xsl:when>
      <xsl:when test="$val = '16'">Improved Disarm</xsl:when>
      <xsl:when test="$val = '17'">Improved Knock</xsl:when>
      <xsl:when test="$val = '18'">Improved Parry</xsl:when>
      <xsl:when test="$val = '19'">Improved Power</xsl:when>
      <xsl:when test="$val = '20'">Improved TwoHanded</xsl:when>
      <xsl:when test="$val = '21'">Improved Strike</xsl:when>
      <xsl:when test="$val = '22'">Iron Will</xsl:when>
      <xsl:when test="$val = '23'">Knock Down</xsl:when>
      <xsl:when test="$val = '24'">Lightning Reflexes</xsl:when>
      <xsl:when test="$val = '25'">Maximize Spell</xsl:when>
      <xsl:when test="$val = '26'">Mobility</xsl:when>
      <xsl:when test="$val = '27'">Point Blank Shot</xsl:when>
      <xsl:when test="$val = '28'">Power Attack</xsl:when>
      <xsl:when test="$val = '29'">Quicken</xsl:when>
      <xsl:when test="$val = '30'">Rapid Shot</xsl:when>
      <xsl:when test="$val = '31'">Sap</xsl:when>
      <xsl:when test="$val = '32'">Shield</xsl:when>
      <xsl:when test="$val = '33'">Silent</xsl:when>
      <xsl:when test="$val = '34'">Skill Focus Anim</xsl:when>
      <xsl:when test="$val = '35'">Spell Focus Abj</xsl:when>
      <xsl:when test="$val = '36'">Spell Pen</xsl:when>
      <xsl:when test="$val = '37'">Still Spell</xsl:when>
      <xsl:when test="$val = '39'">Stunning Fist</xsl:when>
      <xsl:when test="$val = '40'">Toughness</xsl:when>
      <xsl:when test="$val = '41'">TwoWeap</xsl:when>
      <xsl:when test="$val = '42'">WeapFinesse</xsl:when>
      <xsl:when test="$val = '43'">WeapFocClub</xsl:when>
      <xsl:when test="$val = '44'">WeapProfEx</xsl:when>
      <xsl:when test="$val = '45'">WeapProfMar</xsl:when>
      <xsl:when test="$val = '46'">WeapProfSim</xsl:when>
      <xsl:when test="$val = '47'">WeapSpeClub</xsl:when>
      <xsl:when test="$val = '48'">WeapProfDruid</xsl:when>
      <xsl:when test="$val = '49'">WeapProfMonk</xsl:when>
      <xsl:when test="$val = '50'">WeapProfRogue</xsl:when>
      <xsl:when test="$val = '51'">WeapProfWizard</xsl:when>
      <xsl:when test="$val = '52'">ImpCritDagger</xsl:when>
      <xsl:when test="$val = '53'">ImpCritDart</xsl:when>
      <xsl:when test="$val = '54'">ImpCritHXBow</xsl:when>
      <xsl:when test="$val = '55'">ImpCritLgXBow</xsl:when>
      <xsl:when test="$val = '56'">ImpCritLgMace</xsl:when>
      <xsl:when test="$val = '57'">ImpCritMorn</xsl:when>
      <xsl:when test="$val = '58'">ImpCritStaff</xsl:when>
      <xsl:when test="$val = '59'">ImpCritSpear</xsl:when>
      <xsl:when test="$val = '60'">ImpCritSickle</xsl:when>
      <xsl:when test="$val = '61'">ImpCritSling</xsl:when>
      <xsl:when test="$val = '62'">ImpCritUnArm</xsl:when>
      <xsl:when test="$val = '63'">ImpCritLongBow</xsl:when>
      <xsl:when test="$val = '64'">ImpCritShortBow</xsl:when>
      <xsl:when test="$val = '65'">ImpCritShortSword</xsl:when>
      <xsl:when test="$val = '66'">ImpCritRapier</xsl:when>
      <xsl:when test="$val = '67'">ImpCritScim</xsl:when>
      <xsl:when test="$val = '68'">ImpCritLSw</xsl:when>
      <xsl:when test="$val = '69'">ImpCritGSw</xsl:when>
      <xsl:when test="$val = '70'">ImpCritHAxe</xsl:when>
      <xsl:when test="$val = '71'">ImpCritTAxe</xsl:when>
      <xsl:when test="$val = '72'">ImpCritBAxe</xsl:when>
      <xsl:when test="$val = '73'">ImpCritGAxe</xsl:when>
      <xsl:when test="$val = '74'">ImpCritHalb</xsl:when>
      <xsl:when test="$val = '75'">ImpCritLgHam</xsl:when>
      <xsl:when test="$val = '76'">ImpCritLgFlail</xsl:when>
      <xsl:when test="$val = '77'">ImpCritWHam</xsl:when>
      <xsl:when test="$val = '78'">ImpCritHFlail</xsl:when>
      <xsl:when test="$val = '79'">ImpCritKama</xsl:when>
      <xsl:when test="$val = '80'">ImpCritKukri</xsl:when>
      <xsl:when test="$val = '82'">ImpCritShur</xsl:when>
      <xsl:when test="$val = '83'">ImpCritScy</xsl:when>
      <xsl:when test="$val = '84'">ImpCritKatana</xsl:when>
      <xsl:when test="$val = '85'">ImpCritBSw</xsl:when>
      <xsl:when test="$val = '87'">ImpCritDMace</xsl:when>
      <xsl:when test="$val = '88'">ImpCritDAxe</xsl:when>
      <xsl:when test="$val = '89'">ImpCrit2Sw</xsl:when>
      <xsl:when test="$val = '90'">WeapFocDagger</xsl:when>
      <xsl:when test="$val = '91'">WeapFocDart</xsl:when>
      <xsl:when test="$val = '92'">WeapFocHXBow</xsl:when>
      <xsl:when test="$val = '93'">WeapFocLgXBow</xsl:when>
      <xsl:when test="$val = '94'">WeapFocLgMace</xsl:when>
      <xsl:when test="$val = '95'">WeapFocMorn</xsl:when>
      <xsl:when test="$val = '96'">WeapFocStaff</xsl:when>
      <xsl:when test="$val = '97'">WeapFocSpear</xsl:when>
      <xsl:when test="$val = '98'">WeapFocSickle</xsl:when>
      <xsl:when test="$val = '99'">WeapFocSling</xsl:when>
      <xsl:when test="$val = '100'">WeapFocUnArm</xsl:when>
      <xsl:when test="$val = '101'">WeapFocLongBow</xsl:when>
      <xsl:when test="$val = '102'">WeapFocShortBow</xsl:when>
      <xsl:when test="$val = '103'">WeapFocShortSword</xsl:when>
      <xsl:when test="$val = '104'">WeapFocRapier</xsl:when>
      <xsl:when test="$val = '105'">WeapFocScim</xsl:when>
      <xsl:when test="$val = '106'">WeapFocLSw</xsl:when>
      <xsl:when test="$val = '107'">WeapFocGSw</xsl:when>
      <xsl:when test="$val = '108'">WeapFocHAxe</xsl:when>
      <xsl:when test="$val = '109'">WeapFocTAxe</xsl:when>
      <xsl:when test="$val = '110'">WeapFocBAxe</xsl:when>
      <xsl:when test="$val = '111'">WeapFocGAxe</xsl:when>
      <xsl:when test="$val = '112'">WeapFocHalb</xsl:when>
      <xsl:when test="$val = '113'">WeapFocLgHam</xsl:when>
      <xsl:when test="$val = '114'">WeapFocLgFlail</xsl:when>
      <xsl:when test="$val = '115'">WeapFocWHam</xsl:when>
      <xsl:when test="$val = '116'">WeapFocHFlail</xsl:when>
      <xsl:when test="$val = '117'">WeapFocKama</xsl:when>
      <xsl:when test="$val = '118'">WeapFocKukri</xsl:when>
      <xsl:when test="$val = '120'">WeapFocShur</xsl:when>
      <xsl:when test="$val = '121'">WeapFocScy</xsl:when>
      <xsl:when test="$val = '122'">WeapFocKatana</xsl:when>
      <xsl:when test="$val = '123'">WeapFocBSw</xsl:when>
      <xsl:when test="$val = '125'">WeapFocDMace</xsl:when>
      <xsl:when test="$val = '126'">WeapFocDAxe</xsl:when>
      <xsl:when test="$val = '127'">WeapFoc2Sw</xsl:when>
      <xsl:when test="$val = '128'">WeapSpeDagger</xsl:when>
      <xsl:when test="$val = '129'">WeapSpeDart</xsl:when>
      <xsl:when test="$val = '130'">WeapSpeHXBow</xsl:when>
      <xsl:when test="$val = '131'">WeapSpeLgXBow</xsl:when>
      <xsl:when test="$val = '132'">WeapSpeLgMace</xsl:when>
      <xsl:when test="$val = '133'">WeapSpeMorn</xsl:when>
      <xsl:when test="$val = '134'">WeapSpeStaff</xsl:when>
      <xsl:when test="$val = '135'">WeapSpeSpear</xsl:when>
      <xsl:when test="$val = '136'">WeapSpeSickle</xsl:when>
      <xsl:when test="$val = '137'">WeapSpeSling</xsl:when>
      <xsl:when test="$val = '138'">WeapSpeUnArm</xsl:when>
      <xsl:when test="$val = '139'">WeapSpeLongBow</xsl:when>
      <xsl:when test="$val = '140'">WeapSpeShortBow</xsl:when>
      <xsl:when test="$val = '141'">WeapSpeShortSword</xsl:when>
      <xsl:when test="$val = '142'">WeapSpeRapier</xsl:when>
      <xsl:when test="$val = '143'">WeapSpeScim</xsl:when>
      <xsl:when test="$val = '144'">WeapSpeLSw</xsl:when>
      <xsl:when test="$val = '145'">WeapSpeGSw</xsl:when>
      <xsl:when test="$val = '146'">WeapSpeHAxe</xsl:when>
      <xsl:when test="$val = '147'">WeapSpeTAxe</xsl:when>
      <xsl:when test="$val = '148'">WeapSpeBAxe</xsl:when>
      <xsl:when test="$val = '149'">WeapSpeGAxe</xsl:when>
      <xsl:when test="$val = '150'">WeapSpeHalb</xsl:when>
      <xsl:when test="$val = '151'">WeapSpeLgHam</xsl:when>
      <xsl:when test="$val = '152'">WeapSpeLgFlail</xsl:when>
      <xsl:when test="$val = '153'">WeapSpeWHam</xsl:when>
      <xsl:when test="$val = '154'">WeapSpeHFlail</xsl:when>
      <xsl:when test="$val = '155'">WeapSpeKama</xsl:when>
      <xsl:when test="$val = '156'">WeapSpeKukri</xsl:when>
      <xsl:when test="$val = '158'">WeapSpeShur</xsl:when>
      <xsl:when test="$val = '159'">WeapSpeScy</xsl:when>
      <xsl:when test="$val = '160'">WeapSpeKatana</xsl:when>
      <xsl:when test="$val = '161'">WeapSpeBSw</xsl:when>
      <xsl:when test="$val = '163'">WeapSpeDMace</xsl:when>
      <xsl:when test="$val = '164'">WeapSpeDAxe</xsl:when>
      <xsl:when test="$val = '165'">WeapSpe2Sw</xsl:when>
      <xsl:when test="$val = '166'">SpellFocusCon</xsl:when>
      <xsl:when test="$val = '167'">SpellFocusDiv</xsl:when>
      <xsl:when test="$val = '168'">SpellFocusEnc</xsl:when>
      <xsl:when test="$val = '169'">SpellFocusEvo</xsl:when>
      <xsl:when test="$val = '170'">SpellFocusIll</xsl:when>
      <xsl:when test="$val = '171'">SpellFocusNec</xsl:when>
      <xsl:when test="$val = '172'">SpellFocusTra</xsl:when>
      <xsl:when test="$val = '173'">SkillFocusConc</xsl:when>
      <xsl:when test="$val = '174'">SkillFocusDisa</xsl:when>
      <xsl:when test="$val = '175'">SkillFocusDisc</xsl:when>
      <xsl:when test="$val = '177'">SkillFocusHeal</xsl:when>
      <xsl:when test="$val = '178'">SkillFocusHide</xsl:when>
      <xsl:when test="$val = '179'">SkillFocusList</xsl:when>
      <xsl:when test="$val = '180'">SkillFocusLore</xsl:when>
      <xsl:when test="$val = '181'">SkillFocusMove</xsl:when>
      <xsl:when test="$val = '182'">SkillFocusOpen</xsl:when>
      <xsl:when test="$val = '183'">SkillFocusParr</xsl:when>
      <xsl:when test="$val = '184'">SkillFocusPerf</xsl:when>
      <xsl:when test="$val = '185'">SkillFocusPers</xsl:when>
      <xsl:when test="$val = '186'">SkillFocusPick</xsl:when>
      <xsl:when test="$val = '187'">SkillFocusSearch</xsl:when>
      <xsl:when test="$val = '188'">SkillFocusSet</xsl:when>
      <xsl:when test="$val = '189'">SkillFocusSpell</xsl:when>
      <xsl:when test="$val = '190'">SkillFocusSpot</xsl:when>
      <xsl:when test="$val = '192'">SkillFocusTaunt</xsl:when>
      <xsl:when test="$val = '193'">SkillFocusDevi</xsl:when>
      <xsl:when test="$val = '194'">BarbEndurance</xsl:when>
      <xsl:when test="$val = '195'">UncannyDodge1</xsl:when>
      <xsl:when test="$val = '196'">DamageReduction</xsl:when>
      <xsl:when test="$val = '197'">BardicKnowledge</xsl:when>
      <xsl:when test="$val = '198'">NatureSense</xsl:when>
      <xsl:when test="$val = '199'">AnimalCompanion</xsl:when>
      <xsl:when test="$val = '200'">WoodlandStride</xsl:when>
      <xsl:when test="$val = '201'">TracklessStep</xsl:when>
      <xsl:when test="$val = '202'">ResistNatureLure</xsl:when>
      <xsl:when test="$val = '203'">VenomImmunity</xsl:when>
      <xsl:when test="$val = '204'">FlurryofBlows</xsl:when>
      <xsl:when test="$val = '206'">Evasion</xsl:when>
      <xsl:when test="$val = '207'">MonkEndurance</xsl:when>
      <xsl:when test="$val = '208'">StillMind</xsl:when>
      <xsl:when test="$val = '209'">PurityofBody</xsl:when>
      <xsl:when test="$val = '211'">WholenessofBody</xsl:when>
      <xsl:when test="$val = '212'">ImprovedEvasion</xsl:when>
      <xsl:when test="$val = '213'">KiStrike</xsl:when>
      <xsl:when test="$val = '214'">DiamondBody</xsl:when>
      <xsl:when test="$val = '215'">DiamondSoul</xsl:when>
      <xsl:when test="$val = '216'">PerfectSelf</xsl:when>
      <xsl:when test="$val = '217'">DivineGrace</xsl:when>
      <xsl:when test="$val = '219'">DivineHealth</xsl:when>
      <xsl:when test="$val = '221'">SneakAttack</xsl:when>
      <xsl:when test="$val = '222'">CripplingStrike</xsl:when>
      <xsl:when test="$val = '223'">DefensiveRoll</xsl:when>
      <xsl:when test="$val = '224'">Opportunist</xsl:when>
      <xsl:when test="$val = '225'">SkillMastery</xsl:when>
      <xsl:when test="$val = '226'">UncannyReflex</xsl:when>
      <xsl:when test="$val = '227'">stonecunning</xsl:when>
      <xsl:when test="$val = '228'">darkvision</xsl:when>
      <xsl:when test="$val = '229'">hardinesspoisons</xsl:when>
      <xsl:when test="$val = '230'">hardinessspells</xsl:when>
      <xsl:when test="$val = '231'">orctrain</xsl:when>
      <xsl:when test="$val = '232'">gobtrain</xsl:when>
      <xsl:when test="$val = '233'">gianttrain</xsl:when>
      <xsl:when test="$val = '234'">skillaffinitylore</xsl:when>
      <xsl:when test="$val = '235'">immunitysleep</xsl:when>
      <xsl:when test="$val = '236'">hardinessenchantment</xsl:when>
      <xsl:when test="$val = '237'">skillaffinitylisten</xsl:when>
      <xsl:when test="$val = '238'">skillaffinitysearch</xsl:when>
      <xsl:when test="$val = '239'">skillaffinityspot</xsl:when>
      <xsl:when test="$val = '240'">keensense</xsl:when>
      <xsl:when test="$val = '241'">hardinessillusion</xsl:when>
      <xsl:when test="$val = '242'">reptiletrain</xsl:when>
      <xsl:when test="$val = '243'">skillaffinityconcent</xsl:when>
      <xsl:when test="$val = '244'">PSAListen</xsl:when>
      <xsl:when test="$val = '245'">PSASearch</xsl:when>
      <xsl:when test="$val = '246'">PSASpot</xsl:when>
      <xsl:when test="$val = '247'">skillaffinitymovesi</xsl:when>
      <xsl:when test="$val = '248'">lucky</xsl:when>
      <xsl:when test="$val = '249'">fearless</xsl:when>
      <xsl:when test="$val = '250'">good_aim</xsl:when>
      <xsl:when test="$val = '251'">UncannyDodge2</xsl:when>
      <xsl:when test="$val = '252'">UncannyDodge3</xsl:when>
      <xsl:when test="$val = '253'">UncannyDodge4</xsl:when>
      <xsl:when test="$val = '254'">UncannyDodge5</xsl:when>
      <xsl:when test="$val = '255'">UncannyDodge6</xsl:when>
      <xsl:when test="$val = '256'">WeapProfElf</xsl:when>
      <xsl:when test="$val = '257'">BardSongs</xsl:when>
      <xsl:when test="$val = '258'">QuickMaster</xsl:when>
      <xsl:when test="$val = '259'">SlipperMind</xsl:when>
      <xsl:when test="$val = '260'">MonkACBonus</xsl:when>
      <xsl:when test="$val = '261'">FE_Dwarf</xsl:when>
      <xsl:when test="$val = '262'">FE_Elf</xsl:when>
      <xsl:when test="$val = '263'">FE_Gnome</xsl:when>
      <xsl:when test="$val = '264'">FE_Halfling</xsl:when>
      <xsl:when test="$val = '265'">FE_HalfElf</xsl:when>
      <xsl:when test="$val = '266'">FE_HalfOrc</xsl:when>
      <xsl:when test="$val = '267'">FE_Human</xsl:when>
      <xsl:when test="$val = '268'">FE_Aberration</xsl:when>
      <xsl:when test="$val = '269'">FE_Animal</xsl:when>
      <xsl:when test="$val = '270'">FE_Beast</xsl:when>
      <xsl:when test="$val = '271'">FE_Construct</xsl:when>
      <xsl:when test="$val = '272'">FE_Dragon</xsl:when>
      <xsl:when test="$val = '273'">FE_Goblinoid</xsl:when>
      <xsl:when test="$val = '274'">FE_Monstrous</xsl:when>
      <xsl:when test="$val = '275'">FE_Orc</xsl:when>
      <xsl:when test="$val = '276'">FE_Reptilian</xsl:when>
      <xsl:when test="$val = '277'">FE_Elemental</xsl:when>
      <xsl:when test="$val = '278'">FE_Fey</xsl:when>
      <xsl:when test="$val = '279'">FE_Giant</xsl:when>
      <xsl:when test="$val = '280'">FE_Magical_Beast</xsl:when>
      <xsl:when test="$val = '281'">FE_Outsider</xsl:when>
      <xsl:when test="$val = '284'">FE_Shapechanger</xsl:when>
      <xsl:when test="$val = '285'">FE_Undead</xsl:when>
      <xsl:when test="$val = '286'">FE_Vermin</xsl:when>
      <xsl:when test="$val = '289'">WeapProfCreature</xsl:when>
      <xsl:when test="$val = '290'">WeapSpecCreature</xsl:when>
      <xsl:when test="$val = '291'">WeapFocCreature</xsl:when>
      <xsl:when test="$val = '292'">ImpCritCreature</xsl:when>
      <xsl:when test="$val = '293'">BarbarianRage</xsl:when>
      <xsl:when test="$val = '294'">TurnUndead</xsl:when>
      <xsl:when test="$val = '296'">QuiveringPalm</xsl:when>
      <xsl:when test="$val = '297'">EmptyBody</xsl:when>
      <xsl:when test="$val = '299'">LayOnHands</xsl:when>
      <xsl:when test="$val = '300'">AuraCourage</xsl:when>
      <xsl:when test="$val = '301'">SmiteEvil</xsl:when>
      <xsl:when test="$val = '302'">RemoveDisease</xsl:when>
      <xsl:when test="$val = '303'">Familiar</xsl:when>
      <xsl:when test="$val = '304'">ElementalShape</xsl:when>
      <xsl:when test="$val = '305'">WildShape</xsl:when>
      <xsl:when test="$val = '306'">War_Domain_Power</xsl:when>
      <xsl:when test="$val = '307'">Strength_Domain_Power</xsl:when>
      <xsl:when test="$val = '308'">Protection_Domain_Power</xsl:when>
      <xsl:when test="$val = '309'">Luck_Domain_Power</xsl:when>
      <xsl:when test="$val = '310'">Death_Domain_Power</xsl:when>
      <xsl:when test="$val = '311'">Air_Domain_Power</xsl:when>
      <xsl:when test="$val = '312'">Animal_Domain_Power</xsl:when>
      <xsl:when test="$val = '313'">Destruction_Domain_Power</xsl:when>
      <xsl:when test="$val = '314'">Earth_Domain_Power</xsl:when>
      <xsl:when test="$val = '315'">Evil_Domain_Power</xsl:when>
      <xsl:when test="$val = '316'">Fire_Domain_Power</xsl:when>
      <xsl:when test="$val = '317'">Good_Domain_Power</xsl:when>
      <xsl:when test="$val = '318'">Healing_Domain_Power</xsl:when>
      <xsl:when test="$val = '319'">Knowledge_Domain_Power</xsl:when>
      <xsl:when test="$val = '320'">Magic_Domain_Power</xsl:when>
      <xsl:when test="$val = '321'">Plant_Domain_Power</xsl:when>
      <xsl:when test="$val = '322'">Sun_Domain_Power</xsl:when>
      <xsl:when test="$val = '323'">Travel_Domain_Power</xsl:when>
      <xsl:when test="$val = '324'">Trickery_Domain_Power</xsl:when>
      <xsl:when test="$val = '325'">Water_Domain_Power</xsl:when>
      <xsl:when test="$val = '326'">BarbarianRage2</xsl:when>
      <xsl:when test="$val = '327'">BarbarianRage3</xsl:when>
      <xsl:when test="$val = '328'">BarbarianRage4</xsl:when>
      <xsl:when test="$val = '329'">BarbarianRage5</xsl:when>
      <xsl:when test="$val = '330'">BarbarianRage6</xsl:when>
      <xsl:when test="$val = '331'">BarbarianRage7</xsl:when>
      <xsl:when test="$val = '332'">DamageReduction2</xsl:when>
      <xsl:when test="$val = '333'">DamageReduction3</xsl:when>
      <xsl:when test="$val = '334'">DamageReduction4</xsl:when>
      <xsl:when test="$val = '335'">WildShape2</xsl:when>
      <xsl:when test="$val = '336'">WildShape3</xsl:when>
      <xsl:when test="$val = '337'">WildShape4</xsl:when>
      <xsl:when test="$val = '338'">WildShape5</xsl:when>
      <xsl:when test="$val = '339'">WildShape6</xsl:when>
      <xsl:when test="$val = '340'">ElementalShape2</xsl:when>
      <xsl:when test="$val = '341'">ElementalShape3</xsl:when>
      <xsl:when test="$val = '342'">ElementalShape4</xsl:when>
      <xsl:when test="$val = '343'">KiStrike2</xsl:when>
      <xsl:when test="$val = '344'">KiStrike3</xsl:when>
      <xsl:when test="$val = '345'">SneakAttack2</xsl:when>
      <xsl:when test="$val = '346'">SneakAttack3</xsl:when>
      <xsl:when test="$val = '347'">SneakAttack4</xsl:when>
      <xsl:when test="$val = '348'">SneakAttack5</xsl:when>
      <xsl:when test="$val = '349'">SneakAttack6</xsl:when>
      <xsl:when test="$val = '350'">SneakAttack7</xsl:when>
      <xsl:when test="$val = '351'">SneakAttack8</xsl:when>
      <xsl:when test="$val = '352'">SneakAttack9</xsl:when>
      <xsl:when test="$val = '353'">SneakAttack10</xsl:when>
      <xsl:when test="$val = '354'">LowLightVision</xsl:when>
      <xsl:when test="$val = '355'">Bard_Song_02</xsl:when>
      <xsl:when test="$val = '356'">Bard_Song_03</xsl:when>
      <xsl:when test="$val = '357'">Bard_Song_04</xsl:when>
      <xsl:when test="$val = '358'">Bard_Song_05</xsl:when>
      <xsl:when test="$val = '359'">Bard_Song_06</xsl:when>
      <xsl:when test="$val = '360'">Bard_Song_07</xsl:when>
      <xsl:when test="$val = '361'">Bard_Song_08</xsl:when>
      <xsl:when test="$val = '362'">Bard_Song_09</xsl:when>
      <xsl:when test="$val = '363'">Bard_Song_10</xsl:when>
      <xsl:when test="$val = '364'">Bard_Song_11</xsl:when>
      <xsl:when test="$val = '365'">Bard_Song_12</xsl:when>
      <xsl:when test="$val = '366'">Bard_Song_13</xsl:when>
      <xsl:when test="$val = '367'">Bard_Song_14</xsl:when>
      <xsl:when test="$val = '368'">Bard_Song_15</xsl:when>
      <xsl:when test="$val = '369'">Bard_Song_16</xsl:when>
      <xsl:when test="$val = '370'">Bard_Song_17</xsl:when>
      <xsl:when test="$val = '371'">Bard_Song_18</xsl:when>
      <xsl:when test="$val = '372'">Bard_Song_19</xsl:when>
      <xsl:when test="$val = '373'">Bard_Song_20</xsl:when>
      <xsl:when test="$val = '374'">RangerDual</xsl:when>
      <xsl:when test="$val = '375'">Small</xsl:when>
      <xsl:otherwise>
        <xsl:text>(Unknown Feat #</xsl:text>
        <xsl:value-of select="$val"/>
        <xsl:text>)</xsl:text>
      </xsl:otherwise>
    </xsl:choose>
    <xsl:text>,</xsl:text>
  </xsl:template>

  <xsl:template name="nwn:SkillNumToName">
    <xsl:choose>
      <xsl:when test="$val = 0">Animal Empathy</xsl:when>
      <xsl:when test="$val = 1">Concentration</xsl:when>
      <xsl:when test="$val = 2">Disable Trap</xsl:when>
      <xsl:when test="$val = 3">Discipline</xsl:when>
      <xsl:when test="$val = 4">Heal</xsl:when>
      <xsl:when test="$val = 5">Hide</xsl:when>
      <xsl:when test="$val = 6">Listen</xsl:when>
      <xsl:when test="$val = 7">Lore</xsl:when>
      <xsl:when test="$val = 8">Move Silently</xsl:when>
      <xsl:when test="$val = 9">Open Lock</xsl:when>
      <xsl:when test="$val = 10">Parry</xsl:when>
      <xsl:when test="$val = 11">Perform</xsl:when>
      <xsl:when test="$val = 12">Persuade</xsl:when>
      <xsl:when test="$val = 13">Pick Pocket</xsl:when>
      <xsl:when test="$val = 14">Search</xsl:when>
      <xsl:when test="$val = 15">Set Trap</xsl:when>
      <xsl:when test="$val = 16">Spellcraft</xsl:when>
      <xsl:when test="$val = 17">Spot</xsl:when>
      <xsl:when test="$val = 18">Taunt</xsl:when>
      <xsl:when test="$val = 19">Use Magic Device</xsl:when>
      <xsl:otherwise>
        <xsl:text>(Unknown Skill #</xsl:text>
        <xsl:value-of select="$val"/>
        <xsl:text>)</xsl:text>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>

  <xsl:template name="nwn:RaceNumToName">
    <xsl:choose>
      <xsl:when test="$val = 0">Dwarf</xsl:when>
      <xsl:when test="$val = 1">Elf</xsl:when>
      <xsl:when test="$val = 2">Gnome</xsl:when>
      <xsl:when test="$val = 3">Halfling</xsl:when>
      <xsl:when test="$val = 4">Half-Elf</xsl:when>
      <xsl:when test="$val = 5">Half-Orc</xsl:when>
      <xsl:when test="$val = 6">Human</xsl:when>
      <xsl:when test="$val = 7">Aberration</xsl:when>
      <xsl:when test="$val = 8">Animal</xsl:when>
      <xsl:when test="$val = 9">Beast</xsl:when>
      <xsl:when test="$val = 10">Construct</xsl:when>
      <xsl:when test="$val = 11">Dragon</xsl:when>
      <xsl:when test="$val = 12">Humanoid (Goblinoid)</xsl:when>
      <xsl:when test="$val = 13">Humanoid (Monstrous)</xsl:when>
      <xsl:when test="$val = 14">Humanoid (Orc)</xsl:when>
      <xsl:when test="$val = 15">Humanoid (Reptilian)</xsl:when>
      <xsl:when test="$val = 16">Elemental</xsl:when>
      <xsl:when test="$val = 17">Fey</xsl:when>
      <xsl:when test="$val = 18">Giant</xsl:when>
      <xsl:when test="$val = 19">Magical Beast</xsl:when>
      <xsl:when test="$val = 20">Outsider</xsl:when>
      <xsl:when test="$val = 23">Shapechanger</xsl:when>
      <xsl:when test="$val = 24">Undead</xsl:when>
      <xsl:when test="$val = 25">Vermin</xsl:when>
      <xsl:otherwise>
        <xsl:text>(Unknown Race #</xsl:text>
        <xsl:value-of select="$val"/>
        <xsl:text>)</xsl:text>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>

  <xsl:template name="nwn:GenderNumToName">
    <xsl:choose>
      <xsl:when test="$val = 0">Male</xsl:when>
      <xsl:when test="$val = 1">Female</xsl:when>
      <xsl:otherwise>
        <xsl:text>(Unknown Gender #</xsl:text>
        <xsl:value-of select="$val"/>
        <xsl:text>)</xsl:text>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>

  <xsl:template name="nwn:AttToBonus">
    <xsl:value-of select="floor(number($val) div 2.0) - 5.0"/>
  </xsl:template>

  <xsl:template name="nwn:PhenotypeNumToName">
    <xsl:choose>
      <xsl:when test="$val = 0">Slender</xsl:when>
      <xsl:when test="$val = 1">Stocky</xsl:when>
      <xsl:otherwise>
        <xsl:text>(Unknown Phenotype #</xsl:text>
        <xsl:value-of select="$val"/>
        <xsl:text>)</xsl:text>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>

  <xsl:template name="nwn:AlignmentNumsToName">
    <xsl:choose>
	  <xsl:when test="$Law &gt; 66 and $Good &gt; 66">Lawful Good</xsl:when>
	  <xsl:when test="$Law &lt; 34 and $Good &lt; 34">Chaotic Evil</xsl:when>
	  <xsl:when test="$Law &gt; 66 and $Good &lt; 34">Lawful Evil</xsl:when>
	  <xsl:when test="$Law &lt; 34 and $Good &gt; 66">Chaotic Good</xsl:when>
	  <xsl:when test="$Law &gt; 33 and $Law &lt; 67 and $Good &gt; 66">
	    <xsl:text>Neutral Good</xsl:text>
	  </xsl:when>
	  <xsl:when test="$Law &gt; 33 and $Law &lt; 67 and $Good &lt; 34">
	    <xsl:text>Neutral Evil</xsl:text>
	  </xsl:when>
	  <xsl:when test="$Law &lt; 33 and $Good &gt; 33 and $Good &lt; 67">
	    <xsl:text>Chaotic Neutral</xsl:text>
	  </xsl:when>
	  <xsl:when test="$Law &gt; 66 and $Good &gt; 33 and $Good &lt; 67">
	    <xsl:text>Lawful Neutral</xsl:text>
	  </xsl:when>
	  <xsl:otherwise>
	    <xsl:text>True Neutral</xsl:text>
	  </xsl:otherwise>
	</xsl:choose>
  </xsl:template>

  <xsl:template name="nwn:ClassNumToName">
    <xsl:choose>
	  <xsl:when test="$val = 0">Barbarian</xsl:when>
	  <xsl:when test="$val = 1">Bard</xsl:when>
	  <xsl:when test="$val = 2">Cleric</xsl:when>
	  <xsl:when test="$val = 3">Druid</xsl:when>
	  <xsl:when test="$val = 4">Fighter</xsl:when>
	  <xsl:when test="$val = 5">Monk</xsl:when>
	  <xsl:when test="$val = 6">Paladin</xsl:when>
	  <xsl:when test="$val = 7">Ranger</xsl:when>
	  <xsl:when test="$val = 8">Rogue</xsl:when>
	  <xsl:when test="$val = 9">Sorcerer</xsl:when>
	  <xsl:when test="$val = 10">Wizard</xsl:when>
	  <xsl:when test="$val = 11">Aberration</xsl:when>
	  <xsl:when test="$val = 12">Animal</xsl:when>
	  <xsl:when test="$val = 13">Construct</xsl:when>
	  <xsl:when test="$val = 14">Humanoid</xsl:when>
	  <xsl:when test="$val = 15">Monstrous</xsl:when>
	  <xsl:when test="$val = 16">Elemental</xsl:when>
	  <xsl:when test="$val = 17">Fey</xsl:when>
	  <xsl:when test="$val = 18">Dragon</xsl:when>
	  <xsl:when test="$val = 19">Undead</xsl:when>
	  <xsl:when test="$val = 20">Commoner</xsl:when>
	  <xsl:when test="$val = 21">Beast</xsl:when>
	  <xsl:when test="$val = 22">Giant</xsl:when>
	  <xsl:when test="$val = 23">Magic Beast</xsl:when>
	  <xsl:when test="$val = 24">Outsider</xsl:when>
	  <xsl:when test="$val = 25">Shape Changer</xsl:when>
	  <xsl:when test="$val = 26">Vermin</xsl:when>
      <xsl:otherwise>
        <xsl:text>(Unknown Class #</xsl:text>
        <xsl:value-of select="$val"/>
        <xsl:text>)</xsl:text>
      </xsl:otherwise>
	</xsl:choose>
  </xsl:template>

  <xsl:template name="nwn:SpellNumToName">
    <xsl:choose>
	  <xsl:when test="$val = 0">Acid Fog</xsl:when>
	  <xsl:when test="$val = 1">Aid</xsl:when>
	  <xsl:when test="$val = 2">Animate Dead</xsl:when>
	  <xsl:when test="$val = 3">Barkskin</xsl:when>
	  <xsl:when test="$val = 4">Bestow Curse</xsl:when>
	  <xsl:when test="$val = 5">Blade Barrier</xsl:when>
	  <xsl:when test="$val = 6">Bless</xsl:when>
	  <xsl:when test="$val = 7">Bless Weapon</xsl:when>
	  <xsl:when test="$val = 8">Blindness &amp; Deafness</xsl:when>
	  <xsl:when test="$val = 9">Bull's Strength</xsl:when>
	  <xsl:when test="$val = 10">Burning Hands</xsl:when>
	  <xsl:when test="$val = 11">Call Lightning</xsl:when>
	  <xsl:when test="$val = 12">Calm Emotions</xsl:when>
	  <xsl:when test="$val = 13">Cat's Grace</xsl:when>
	  <xsl:when test="$val = 14">Chain Lightning</xsl:when>
	  <xsl:when test="$val = 15">Charm Monster</xsl:when>
	  <xsl:when test="$val = 16">Charm Person</xsl:when>
	  <xsl:when test="$val = 17">Charm Person or Animal</xsl:when>
	  <xsl:when test="$val = 18">Circle of Death</xsl:when>
	  <xsl:when test="$val = 19">Circle of Doom</xsl:when>
	  <xsl:when test="$val = 20">Clairaudience and Clairvoyance</xsl:when>
	  <xsl:when test="$val = 21">Clarity</xsl:when>
	  <xsl:when test="$val = 22">Cloak of Chaos</xsl:when>
	  <xsl:when test="$val = 23">Cloudkill</xsl:when>
	  <xsl:when test="$val = 24">Color Spray</xsl:when>
	  <xsl:when test="$val = 25">Cone of Cold</xsl:when>
	  <xsl:when test="$val = 26">Confusion</xsl:when>
	  <xsl:when test="$val = 27">Contagion</xsl:when>
	  <xsl:when test="$val = 28">Control Undead</xsl:when>
	  <xsl:when test="$val = 29">Create Greater Undead</xsl:when>
	  <xsl:when test="$val = 30">Create Undead</xsl:when>
	  <xsl:when test="$val = 31">Cure Critical Wounds</xsl:when>
	  <xsl:when test="$val = 32">Cure Light Wounds</xsl:when>
	  <xsl:when test="$val = 33">Cure Minor Wounds</xsl:when>
	  <xsl:when test="$val = 34">Cure Moderate Wounds</xsl:when>
	  <xsl:when test="$val = 35">Cure Serious Wounds</xsl:when>
	  <xsl:when test="$val = 36">Darkness</xsl:when>
	  <xsl:when test="$val = 37">Daze</xsl:when>
	  <xsl:when test="$val = 38">Death Ward</xsl:when>
	  <xsl:when test="$val = 39">Delayed Blast Fireball</xsl:when>
	  <xsl:when test="$val = 40">Dismissal</xsl:when>
	  <xsl:when test="$val = 41">Dispel Magic</xsl:when>
	  <xsl:when test="$val = 42">Divine Power</xsl:when>
	  <xsl:when test="$val = 43">Dominate Animal</xsl:when>
	  <xsl:when test="$val = 44">Dominate Monster</xsl:when>
	  <xsl:when test="$val = 45">Dominate Person</xsl:when>
	  <xsl:when test="$val = 46">Doom</xsl:when>
	  <xsl:when test="$val = 47">Elemental Shield</xsl:when>
	  <xsl:when test="$val = 48">Elemental Swarm</xsl:when>
	  <xsl:when test="$val = 49">Endurance</xsl:when>
	  <xsl:when test="$val = 50">Endure Elements</xsl:when>
	  <xsl:when test="$val = 51">Energy Drain</xsl:when>
	  <xsl:when test="$val = 52">Enervation</xsl:when>
	  <xsl:when test="$val = 53">Entangle</xsl:when>
	  <xsl:when test="$val = 54">Fear</xsl:when>
	  <xsl:when test="$val = 55">Feeblemind</xsl:when>
	  <xsl:when test="$val = 56">Finger of Death</xsl:when>
	  <xsl:when test="$val = 57">Fire Storm</xsl:when>
	  <xsl:when test="$val = 58">Fireball</xsl:when>
	  <xsl:when test="$val = 59">Flame Arrow</xsl:when>
	  <xsl:when test="$val = 60">Flame Lash</xsl:when>
	  <xsl:when test="$val = 61">Flame Strike</xsl:when>
	  <xsl:when test="$val = 62">Freedom of Movement</xsl:when>
	  <xsl:when test="$val = 63">Gate</xsl:when>
	  <xsl:when test="$val = 64">Ghoul Touch</xsl:when>
	  <xsl:when test="$val = 65">Globe of Invulnerability</xsl:when>
	  <xsl:when test="$val = 66">Grease</xsl:when>
	  <xsl:when test="$val = 67">Greater Dispelling</xsl:when>
	  <xsl:when test="$val = 68">Greater Magic Weapon</xsl:when>
	  <xsl:when test="$val = 69">Greater Planar Binding</xsl:when>
	  <xsl:when test="$val = 70">Greater Restoration</xsl:when>
	  <xsl:when test="$val = 71">Greater Shadow Conjuration</xsl:when>
	  <xsl:when test="$val = 72">Greater Spell Breach</xsl:when>
	  <xsl:when test="$val = 73">Greater Spell Mantle</xsl:when>
	  <xsl:when test="$val = 74">Greater Stoneskin</xsl:when>
	  <xsl:when test="$val = 75">Gust of Wind</xsl:when>
	  <xsl:when test="$val = 76">Hammer of the Gods</xsl:when>
	  <xsl:when test="$val = 77">Harm</xsl:when>
	  <xsl:when test="$val = 78">Haste</xsl:when>
	  <xsl:when test="$val = 79">Heal</xsl:when>
	  <xsl:when test="$val = 80">Healing Circle</xsl:when>
	  <xsl:when test="$val = 81">Hold Animal</xsl:when>
	  <xsl:when test="$val = 82">Hold Monster</xsl:when>
	  <xsl:when test="$val = 83">Hold Person</xsl:when>
	  <xsl:when test="$val = 84">Holy Aura</xsl:when>
	  <xsl:when test="$val = 85">Holy Sword</xsl:when>
	  <xsl:when test="$val = 86">Identify</xsl:when>
	  <xsl:when test="$val = 87">Implosion</xsl:when>
	  <xsl:when test="$val = 88">Improved Invisibility</xsl:when>
	  <xsl:when test="$val = 89">Incendiary Cloud</xsl:when>
	  <xsl:when test="$val = 90">Invisibility</xsl:when>
	  <xsl:when test="$val = 91">Invisibility Purge</xsl:when>
	  <xsl:when test="$val = 92">Invisibility Sphere</xsl:when>
	  <xsl:when test="$val = 93">Knock</xsl:when>
	  <xsl:when test="$val = 94">Lesser Dispel</xsl:when>
	  <xsl:when test="$val = 95">Lesser Mind Blank</xsl:when>
	  <xsl:when test="$val = 96">Lesser Planar Binding</xsl:when>
	  <xsl:when test="$val = 97">Lesser Restoration</xsl:when>
	  <xsl:when test="$val = 98">Lesser Spell Breach</xsl:when>
	  <xsl:when test="$val = 99">Lesser Spell Mantle</xsl:when>
	  <xsl:when test="$val = 100">Light</xsl:when>
	  <xsl:when test="$val = 101">Lightning Bolt</xsl:when>
	  <xsl:when test="$val = 102">Mage Armor</xsl:when>
	  <xsl:when test="$val = 103">Magic Circle Against Chaos</xsl:when>
	  <xsl:when test="$val = 104">Magic Circle Against Evil</xsl:when>
	  <xsl:when test="$val = 105">Magic Circle Against Good</xsl:when>
	  <xsl:when test="$val = 106">Magic Circle Against Law</xsl:when>
	  <xsl:when test="$val = 107">Magic Missile</xsl:when>
	  <xsl:when test="$val = 108">Magic Vestment</xsl:when>
	  <xsl:when test="$val = 109">Magic Weapon</xsl:when>
	  <xsl:when test="$val = 110">Mass Blindness &amp; Deafness</xsl:when>
	  <xsl:when test="$val = 111">Mass Charm</xsl:when>
	  <xsl:when test="$val = 112">Mass Domination</xsl:when>
	  <xsl:when test="$val = 113">Mass Haste</xsl:when>
	  <xsl:when test="$val = 114">Mass Heal</xsl:when>
	  <xsl:when test="$val = 115">Melf's Acid Arrow</xsl:when>
	  <xsl:when test="$val = 116">Meteor Swarm</xsl:when>
	  <xsl:when test="$val = 117">Mind Blank</xsl:when>
	  <xsl:when test="$val = 118">Mind Fog</xsl:when>
	  <xsl:when test="$val = 119">Minor Globe of Invulnerability</xsl:when>
	  <xsl:when test="$val = 120">Ghostly Visage</xsl:when>
	  <xsl:when test="$val = 121">Ethereal Visage</xsl:when>
	  <xsl:when test="$val = 122">Mordenkainen's Disjunction</xsl:when>
	  <xsl:when test="$val = 123">Mordenkainen's Sword</xsl:when>
	  <xsl:when test="$val = 124">Nature's Balance</xsl:when>
	  <xsl:when test="$val = 125">Negative Energy Protection</xsl:when>
	  <xsl:when test="$val = 126">Neutralize Poison</xsl:when>
	  <xsl:when test="$val = 127">Phantasmal Killer</xsl:when>
	  <xsl:when test="$val = 128">Planar Binding</xsl:when>
	  <xsl:when test="$val = 129">Poison</xsl:when>
	  <xsl:when test="$val = 130">Polymorph Self</xsl:when>
	  <xsl:when test="$val = 131">Power Word Kill</xsl:when>
	  <xsl:when test="$val = 132">Power Word Stun</xsl:when>
	  <xsl:when test="$val = 133">Prayer</xsl:when>
	  <xsl:when test="$val = 134">Premonition</xsl:when>
	  <xsl:when test="$val = 135">Prismatic Spray</xsl:when>
	  <xsl:when test="$val = 136">Protection from Chaos</xsl:when>
	  <xsl:when test="$val = 137">Protection from Elements</xsl:when>
	  <xsl:when test="$val = 138">Protection from Evil</xsl:when>
	  <xsl:when test="$val = 139">Protection from Good</xsl:when>
	  <xsl:when test="$val = 140">Protection from Law</xsl:when>
	  <xsl:when test="$val = 141">Protection from Spells</xsl:when>
	  <xsl:when test="$val = 142">Raise Dead</xsl:when>
	  <xsl:when test="$val = 143">Ray of Enfeeblement</xsl:when>
	  <xsl:when test="$val = 144">Ray of Frost</xsl:when>
	  <xsl:when test="$val = 145">Remove Blindness &amp; Deafness</xsl:when>
	  <xsl:when test="$val = 146">Remove Curse</xsl:when>
	  <xsl:when test="$val = 147">Remove Disease</xsl:when>
	  <xsl:when test="$val = 148">Remove Fear</xsl:when>
	  <xsl:when test="$val = 149">Remove Paralysis</xsl:when>
	  <xsl:when test="$val = 150">Resist Elements</xsl:when>
	  <xsl:when test="$val = 151">Resistance</xsl:when>
	  <xsl:when test="$val = 152">Restoration</xsl:when>
	  <xsl:when test="$val = 153">Ressurection</xsl:when>
	  <xsl:when test="$val = 154">Sanctuary</xsl:when>
	  <xsl:when test="$val = 155">Scare</xsl:when>
	  <xsl:when test="$val = 156">Searing Light</xsl:when>
	  <xsl:when test="$val = 157">See Invisibility</xsl:when>
	  <xsl:when test="$val = 158">Shades</xsl:when>
	  <xsl:when test="$val = 159">Shadow Conjuration</xsl:when>
	  <xsl:when test="$val = 160">Shadow Shield</xsl:when>
	  <xsl:when test="$val = 161">Shape Change</xsl:when>
	  <xsl:when test="$val = 162">Shield of Law</xsl:when>
	  <xsl:when test="$val = 163">Silence</xsl:when>
	  <xsl:when test="$val = 164">Slay Living</xsl:when>
	  <xsl:when test="$val = 165">Sleep</xsl:when>
	  <xsl:when test="$val = 166">Slow</xsl:when>
	  <xsl:when test="$val = 167">Sound Burst</xsl:when>
	  <xsl:when test="$val = 168">Spell Resistance</xsl:when>
	  <xsl:when test="$val = 169">Spell Mantle</xsl:when>
	  <xsl:when test="$val = 170">Sphere of Chaos</xsl:when>
	  <xsl:when test="$val = 171">Stinking Cloud</xsl:when>
	  <xsl:when test="$val = 172">Stoneskin</xsl:when>
	  <xsl:when test="$val = 173">Storm of Vengeance</xsl:when>
	  <xsl:when test="$val = 174">Summon Creature I</xsl:when>
	  <xsl:when test="$val = 175">Summon Creature II</xsl:when>
	  <xsl:when test="$val = 176">Summon Creature III</xsl:when>
	  <xsl:when test="$val = 177">Summon Creature IV</xsl:when>
	  <xsl:when test="$val = 178">Summon Creature IX</xsl:when>
	  <xsl:when test="$val = 179">Summon Creature V</xsl:when>
	  <xsl:when test="$val = 180">Summon Creature VI</xsl:when>
	  <xsl:when test="$val = 181">Summon Creature VII</xsl:when>
	  <xsl:when test="$val = 182">Summon Creature VIII</xsl:when>
	  <xsl:when test="$val = 183">Sunbeam</xsl:when>
	  <xsl:when test="$val = 184">Tenser's Transformation</xsl:when>
	  <xsl:when test="$val = 185">Time Stop</xsl:when>
	  <xsl:when test="$val = 186">True Seeing</xsl:when>
	  <xsl:when test="$val = 187">Unholy Aura</xsl:when>
	  <xsl:when test="$val = 188">Vampiric Touch</xsl:when>
	  <xsl:when test="$val = 189">Virtue</xsl:when>
	  <xsl:when test="$val = 190">Wail of the Banshee</xsl:when>
	  <xsl:when test="$val = 191">Wall of Fire</xsl:when>
	  <xsl:when test="$val = 192">Web</xsl:when>
	  <xsl:when test="$val = 193">Weird</xsl:when>
	  <xsl:when test="$val = 194">Word of Faith</xsl:when>
	  <xsl:when test="$val = 195">Aura of Blinding</xsl:when>
	  <xsl:when test="$val = 196">Aura of Cold</xsl:when>
	  <xsl:when test="$val = 197">Aura of Electricity</xsl:when>
	  <xsl:when test="$val = 198">Aura of Fear</xsl:when>
	  <xsl:when test="$val = 199">Aura of Fire</xsl:when>
	  <xsl:when test="$val = 200">Aura of Menace</xsl:when>
	  <xsl:when test="$val = 201">Aura of Protection</xsl:when>
	  <xsl:when test="$val = 202">Aura of Stun</xsl:when>
	  <xsl:when test="$val = 203">Aura of Unearthly Visage</xsl:when>
	  <xsl:when test="$val = 204">Aura of Unnatural</xsl:when>
	  <xsl:when test="$val = 205">Bolt of Charisma Drain</xsl:when>
	  <xsl:when test="$val = 206">Bolt of Constitution Drain</xsl:when>
	  <xsl:when test="$val = 207">Bolt of Dexterity Drain</xsl:when>
	  <xsl:when test="$val = 208">Bolt of Intelligence Drain</xsl:when>
	  <xsl:when test="$val = 209">Bolt of Strength Drain</xsl:when>
	  <xsl:when test="$val = 210">Bolt of Wisdom Drain</xsl:when>
	  <xsl:when test="$val = 211">Bolt of Acid</xsl:when>
	  <xsl:when test="$val = 212">Bolt of Charm</xsl:when>
	  <xsl:when test="$val = 213">Bolt of Cold</xsl:when>
	  <xsl:when test="$val = 214">Bolt of Confuse</xsl:when>
	  <xsl:when test="$val = 215">Bolt of Daze</xsl:when>
	  <xsl:when test="$val = 216">Bolt of Death</xsl:when>
	  <xsl:when test="$val = 217">Bolt of Disease</xsl:when>
	  <xsl:when test="$val = 218">Bolt of Dominate</xsl:when>
	  <xsl:when test="$val = 219">Bolt of Fire</xsl:when>
	  <xsl:when test="$val = 220">Bolt of Knockdown</xsl:when>
	  <xsl:when test="$val = 221">Bolt of Level Drain</xsl:when>
	  <xsl:when test="$val = 222">Bolt of Lightning</xsl:when>
	  <xsl:when test="$val = 223">Bolt of Paralyze</xsl:when>
	  <xsl:when test="$val = 224">Bolt of Poison</xsl:when>
	  <xsl:when test="$val = 225">Bolt of Shards</xsl:when>
	  <xsl:when test="$val = 226">Bolt of Slow</xsl:when>
	  <xsl:when test="$val = 227">Bolt of Stun</xsl:when>
	  <xsl:when test="$val = 228">Bolt of Web</xsl:when>
	  <xsl:when test="$val = 229">Cone of Acid</xsl:when>
	  <xsl:when test="$val = 230">Cone of Cold</xsl:when>
	  <xsl:when test="$val = 231">Cone of Disease</xsl:when>
	  <xsl:when test="$val = 232">Cone of Fire</xsl:when>
	  <xsl:when test="$val = 233">Cone of Lightning</xsl:when>
	  <xsl:when test="$val = 234">Cone of Poison</xsl:when>
	  <xsl:when test="$val = 235">Cone of Sound</xsl:when>
	  <xsl:when test="$val = 236">Dragon Breath Acid</xsl:when>
	  <xsl:when test="$val = 237">Dragon Breath Cold</xsl:when>
	  <xsl:when test="$val = 238">Dragon Breath Fear</xsl:when>
	  <xsl:when test="$val = 239">Dragon Breath Fire</xsl:when>
	  <xsl:when test="$val = 240">Dragon Breath Gas</xsl:when>
	  <xsl:when test="$val = 241">Dragon Breath Lightning</xsl:when>
	  <xsl:when test="$val = 242">Dragon Breath Paralyze</xsl:when>
	  <xsl:when test="$val = 243">Dragon Breath Sleep</xsl:when>
	  <xsl:when test="$val = 244">Dragon Breath Slow</xsl:when>
	  <xsl:when test="$val = 245">Dragon Breath Weaken</xsl:when>
	  <xsl:when test="$val = 246">Dragon Wing Buffet</xsl:when>
	  <xsl:when test="$val = 247">Ferocity 1</xsl:when>
	  <xsl:when test="$val = 248">Ferocity 2</xsl:when>
	  <xsl:when test="$val = 249">Ferocity 3</xsl:when>
	  <xsl:when test="$val = 250">Gaze of Charm</xsl:when>
	  <xsl:when test="$val = 251">Gaze of Confusion</xsl:when>
	  <xsl:when test="$val = 252">Gaze of Daze</xsl:when>
	  <xsl:when test="$val = 253">Gaze of Death</xsl:when>
	  <xsl:when test="$val = 254">Gaze of Chaos Destruction</xsl:when>
	  <xsl:when test="$val = 255">Gaze of Evil Destruction</xsl:when>
	  <xsl:when test="$val = 256">Gaze of Good Destruction</xsl:when>
	  <xsl:when test="$val = 257">Gaze of Law Destruction</xsl:when>
	  <xsl:when test="$val = 258">Gaze of Domination</xsl:when>
	  <xsl:when test="$val = 259">Gaze of Doom</xsl:when>
	  <xsl:when test="$val = 260">Gaze of Fear</xsl:when>
	  <xsl:when test="$val = 261">Gaze of Paralysis</xsl:when>
	  <xsl:when test="$val = 262">Gaze of Stunning</xsl:when>
	  <xsl:when test="$val = 263">Golem Breath Gas</xsl:when>
	  <xsl:when test="$val = 264">Hell Hound Firebreath</xsl:when>
	  <xsl:when test="$val = 265">Howl of Confusion</xsl:when>
	  <xsl:when test="$val = 266">Howl of Daze</xsl:when>
	  <xsl:when test="$val = 267">Howl of Death</xsl:when>
	  <xsl:when test="$val = 268">Howl of Doom</xsl:when>
	  <xsl:when test="$val = 269">Howl of Fear</xsl:when>
	  <xsl:when test="$val = 270">Howl of Paralysis</xsl:when>
	  <xsl:when test="$val = 271">Howl of Sound</xsl:when>
	  <xsl:when test="$val = 272">Howl of Stun</xsl:when>
	  <xsl:when test="$val = 273">Intensity 1</xsl:when>
	  <xsl:when test="$val = 274">Intensity 2</xsl:when>
	  <xsl:when test="$val = 275">Intensity 3</xsl:when>
	  <xsl:when test="$val = 276">Krenshar Scare</xsl:when>
	  <xsl:when test="$val = 277">Lesser Body Adjustment</xsl:when>
	  <xsl:when test="$val = 278">Mephit Salt Breath</xsl:when>
	  <xsl:when test="$val = 279">Mephit Steam Breath</xsl:when>
	  <xsl:when test="$val = 280">Mummy Bolster Undead</xsl:when>
	  <xsl:when test="$val = 281">Pulse of Drowning</xsl:when>
	  <xsl:when test="$val = 282">Pulse of Spores</xsl:when>
	  <xsl:when test="$val = 283">Pulse of Whirlwind</xsl:when>
	  <xsl:when test="$val = 284">Pulse of Fire</xsl:when>
	  <xsl:when test="$val = 285">Pulse of Lightning</xsl:when>
	  <xsl:when test="$val = 286">Pulse of Cold</xsl:when>
	  <xsl:when test="$val = 287">Pulse of Negative Energy</xsl:when>
	  <xsl:when test="$val = 288">Pulse of Holiness</xsl:when>
	  <xsl:when test="$val = 289">Pulse of Death</xsl:when>
	  <xsl:when test="$val = 290">Pulse of Level Drain</xsl:when>
	  <xsl:when test="$val = 291">Pulse of Intelligence Drain</xsl:when>
	  <xsl:when test="$val = 292">Pulse of Charisma Drain</xsl:when>
	  <xsl:when test="$val = 293">Pulse of Constitution Drain</xsl:when>
	  <xsl:when test="$val = 294">Pulse of Dexterity Drain</xsl:when>
	  <xsl:when test="$val = 295">Pulse of Strength Drain</xsl:when>
	  <xsl:when test="$val = 296">Pulse of Wisdom Drain</xsl:when>
	  <xsl:when test="$val = 297">Pulse of Poison</xsl:when>
	  <xsl:when test="$val = 298">Pulse of Disease</xsl:when>
	  <xsl:when test="$val = 299">Rage 3</xsl:when>
	  <xsl:when test="$val = 300">Rage 4</xsl:when>
	  <xsl:when test="$val = 301">Rage 5</xsl:when>
	  <xsl:when test="$val = 302">Smoke Claw</xsl:when>
	  <xsl:when test="$val = 303">Summon Slaad</xsl:when>
	  <xsl:when test="$val = 304">Summon Tanarri</xsl:when>
	  <xsl:when test="$val = 305">Trumpet Blast</xsl:when>
	  <xsl:when test="$val = 306">Tyrant Fog Mist</xsl:when>
	  <xsl:when test="$val = 307">Barbarian Rage</xsl:when>
	  <xsl:when test="$val = 308">Turn Undead</xsl:when>
	  <xsl:when test="$val = 309">Wholeness of Body</xsl:when>
	  <xsl:when test="$val = 310">Quivering Palm</xsl:when>
	  <xsl:when test="$val = 311">Empty Body</xsl:when>
	  <xsl:when test="$val = 312">Detect Evil</xsl:when>
	  <xsl:when test="$val = 313">Lay on Hands</xsl:when>
	  <xsl:when test="$val = 314">Aura of Courage</xsl:when>
	  <xsl:when test="$val = 315">Smite Evil</xsl:when>
	  <xsl:when test="$val = 316">Remove Disease</xsl:when>
	  <xsl:when test="$val = 317">Summon Animal Companion</xsl:when>
	  <xsl:when test="$val = 318">Summon Familiar</xsl:when>
	  <xsl:when test="$val = 319">Elemental Shape</xsl:when>
	  <xsl:when test="$val = 320">Wild Shape</xsl:when>
	  <xsl:when test="$val = 321">Protection from Alignment</xsl:when>
	  <xsl:when test="$val = 322">Magic Circle against Alignment</xsl:when>
	  <xsl:when test="$val = 323">Aura vs. Alignment</xsl:when>
	  <xsl:when test="$val = 324">Shades Summon Shadow</xsl:when>
	  <xsl:when test="$val = 340">Shades Cone of Cold</xsl:when>
	  <xsl:when test="$val = 341">Shades Fireball</xsl:when>
	  <xsl:when test="$val = 342">Shades Stoneskin</xsl:when>
	  <xsl:when test="$val = 343">Shades Wall of Fire</xsl:when>
	  <xsl:when test="$val = 344">Shadow Con Summon Shadow</xsl:when>
	  <xsl:when test="$val = 345">Shadow Con Darkness</xsl:when>
	  <xsl:when test="$val = 346">Shadow Con Invisibility</xsl:when>
	  <xsl:when test="$val = 347">Shadow Con Mage Armor</xsl:when>
	  <xsl:when test="$val = 348">Shadow Con Magic Missile</xsl:when>
	  <xsl:when test="$val = 349">Greater Shadow Con Summon Shadow</xsl:when>
	  <xsl:when test="$val = 350">Greater Shadow Con Acid Arrow</xsl:when>
	  <xsl:when test="$val = 351">Greater Shadow Con Ghostly Visage</xsl:when>
	  <xsl:when test="$val = 352">Greater Shadow Con Web</xsl:when>
	  <xsl:when test="$val = 353">Greater Shadow Con Minor Globe of Invulnerability</xsl:when>
	  <xsl:when test="$val = 354">Eagle's Splendor</xsl:when>
	  <xsl:when test="$val = 355">Owl's Wisdom</xsl:when>
	  <xsl:when test="$val = 356">Fox's Cunning</xsl:when>
	  <xsl:when test="$val = 357">Greater Eagle's Splendor</xsl:when>
	  <xsl:when test="$val = 358">Greater Owl's Wisdom</xsl:when>
	  <xsl:when test="$val = 359">Greater Fox's Cunning</xsl:when>
	  <xsl:when test="$val = 360">Greater Bull's Strength</xsl:when>
	  <xsl:when test="$val = 361">Greater Cat's Grace</xsl:when>
	  <xsl:when test="$val = 362">Greater Endurance</xsl:when>
	  <xsl:when test="$val = 363">Awaken</xsl:when>
	  <xsl:when test="$val = 364">Creeping Doom</xsl:when>
	  <xsl:when test="$val = 365">Ultravision</xsl:when>
	  <xsl:when test="$val = 366">Destruction</xsl:when>
	  <xsl:when test="$val = 367">Horrid Wilting</xsl:when>
	  <xsl:when test="$val = 368">Ice Storm</xsl:when>
	  <xsl:when test="$val = 369">Energy Buffer</xsl:when>
	  <xsl:when test="$val = 370">Negative Energy Burst</xsl:when>
	  <xsl:when test="$val = 371">Negative Energy Ray</xsl:when>
	  <xsl:when test="$val = 372">Aura of Vitality</xsl:when>
	  <xsl:when test="$val = 373">War Cry</xsl:when>
	  <xsl:when test="$val = 374">Regenerate</xsl:when>
	  <xsl:when test="$val = 375">Evard's Black Tentacles</xsl:when>
	  <xsl:when test="$val = 376">Legend Lore</xsl:when>
	  <xsl:when test="$val = 377">Find Traps</xsl:when>
	  <xsl:when test="$val = 378">Summon Mephit</xsl:when>
	  <xsl:when test="$val = 379">Summon Celestial</xsl:when>
	  <xsl:when test="$val = 380">Battle Mastery Spell</xsl:when>
	  <xsl:when test="$val = 381">Divine Strength</xsl:when>
	  <xsl:when test="$val = 382">Divine Protection</xsl:when>
	  <xsl:when test="$val = 383">Negative Plane Avatar</xsl:when>
	  <xsl:when test="$val = 384">Divine Trickery</xsl:when>
	  <xsl:when test="$val = 385">Rogue's Cunning</xsl:when>
	  <xsl:when test="$val = 386">Activate Item</xsl:when>
	  <xsl:when test="$val = 387">Polymorph Giant Spider</xsl:when>
	  <xsl:when test="$val = 388">Polymorph Troll</xsl:when>
	  <xsl:when test="$val = 389">Polymorph Umber Hulk</xsl:when>
	  <xsl:when test="$val = 390">Polymorph Pixie</xsl:when>
	  <xsl:when test="$val = 391">Polymorph Zombie</xsl:when>
	  <xsl:when test="$val = 392">Shapechange Red Dragon</xsl:when>
	  <xsl:when test="$val = 393">Shapechange Fire Giant</xsl:when>
	  <xsl:when test="$val = 394">Shapechange Balor</xsl:when>
	  <xsl:when test="$val = 395">Shapechange Death Slaad</xsl:when>
	  <xsl:when test="$val = 396">Shapechange Iron Golem</xsl:when>
	  <xsl:when test="$val = 397">Elemental Shape Fire</xsl:when>
	  <xsl:when test="$val = 398">Elemental Shape Water</xsl:when>
	  <xsl:when test="$val = 399">Elemental Shape Earth</xsl:when>
	  <xsl:when test="$val = 400">Elemental Shape Air</xsl:when>
	  <xsl:when test="$val = 401">Wild Shape Brown Bear</xsl:when>
	  <xsl:when test="$val = 402">Wild Shape Panther</xsl:when>
	  <xsl:when test="$val = 403">Wild Shape Wolf</xsl:when>
	  <xsl:when test="$val = 404">Wild Shape Boar</xsl:when>
	  <xsl:when test="$val = 405">Wild Shape Badger</xsl:when>
	  <xsl:when test="$val = 406">Special Alcohol Beer</xsl:when>
	  <xsl:when test="$val = 407">Special Alcohol Wine</xsl:when>
	  <xsl:when test="$val = 408">Special Alcohol Spirits</xsl:when>
	  <xsl:when test="$val = 409">Special Herb Belladonna</xsl:when>
	  <xsl:when test="$val = 410">Special Herb Garlic</xsl:when>
	  <xsl:when test="$val = 411">Bard's Song</xsl:when>
	  <xsl:when test="$val = 412">Aura Fear Dragon</xsl:when>
	  <xsl:when test="$val = 413">Activate Item Self</xsl:when>
      <xsl:otherwise>
        <xsl:text>(Unknown Spell #</xsl:text>
        <xsl:value-of select="$val"/>
        <xsl:text>)</xsl:text>
      </xsl:otherwise>
	</xsl:choose>
  </xsl:template>

  <xsl:template name="nwn:KnownSpells">
	<h2>Known Spells</h2>
	<table>
	  <tr>
	    <th>Level</th><th>Spell</th><th>Metamagic</th>
	  </tr>
      <xsl:for-each select="/nwn:UTC/nwn:OBJECT[@NAME='ClassList']/nwn:LIST/nwn:LISTITEM/nwn:OBJECT[@NAME='KnownList0']/nwn:LIST/nwn:LISTITEM">
		<tr>
		  <td>0</td>
		  <td>
	        <xsl:call-template name="nwn:SpellNumToName">
	          <xsl:with-param name="val" select="nwn:OBJECT[@NAME='Spell']/nwn:SCALAR/attribute::VALUE"/>
	        </xsl:call-template>
		  </td>
		  <td>
		    <xsl:value-of select="nwn:OBJECT[@NAME='SpellMetaMagic']/nwn:SCALAR/attribute::VALUE"/>
		  </td>
		</tr>
	  </xsl:for-each>
      <xsl:for-each select="/nwn:UTC/nwn:OBJECT[@NAME='ClassList']/nwn:LIST/nwn:LISTITEM/nwn:OBJECT[@NAME='KnownList1']/nwn:LIST/nwn:LISTITEM">
		<tr>
		  <td>1</td>
		  <td>
	        <xsl:call-template name="nwn:SpellNumToName">
	          <xsl:with-param name="val" select="nwn:OBJECT[@NAME='Spell']/nwn:SCALAR/attribute::VALUE"/>
	        </xsl:call-template>
		  </td>
		  <td>
		    <xsl:value-of select="nwn:OBJECT[@NAME='SpellMetaMagic']/nwn:SCALAR/attribute::VALUE"/>
		  </td>
		</tr>
	  </xsl:for-each>
      <xsl:for-each select="/nwn:UTC/nwn:OBJECT[@NAME='ClassList']/nwn:LIST/nwn:LISTITEM/nwn:OBJECT[@NAME='KnownList2']/nwn:LIST/nwn:LISTITEM">
		<tr>
		  <td>2</td>
		  <td>
	        <xsl:call-template name="nwn:SpellNumToName">
	          <xsl:with-param name="val" select="nwn:OBJECT[@NAME='Spell']/nwn:SCALAR/attribute::VALUE"/>
	        </xsl:call-template>
		  </td>
		  <td>
		    <xsl:value-of select="nwn:OBJECT[@NAME='SpellMetaMagic']/nwn:SCALAR/attribute::VALUE"/>
		  </td>
		</tr>
	  </xsl:for-each>
      <xsl:for-each select="/nwn:UTC/nwn:OBJECT[@NAME='ClassList']/nwn:LIST/nwn:LISTITEM/nwn:OBJECT[@NAME='KnownList3']/nwn:LIST/nwn:LISTITEM">
		<tr>
		  <td>3</td>
		  <td>
	        <xsl:call-template name="nwn:SpellNumToName">
	          <xsl:with-param name="val" select="nwn:OBJECT[@NAME='Spell']/nwn:SCALAR/attribute::VALUE"/>
	        </xsl:call-template>
		  </td>
		  <td>
		    <xsl:value-of select="nwn:OBJECT[@NAME='SpellMetaMagic']/nwn:SCALAR/attribute::VALUE"/>
		  </td>
		</tr>
	  </xsl:for-each>
      <xsl:for-each select="/nwn:UTC/nwn:OBJECT[@NAME='ClassList']/nwn:LIST/nwn:LISTITEM/nwn:OBJECT[@NAME='KnownList4']/nwn:LIST/nwn:LISTITEM">
		<tr>
		  <td>4</td>
		  <td>
	        <xsl:call-template name="nwn:SpellNumToName">
	          <xsl:with-param name="val" select="nwn:OBJECT[@NAME='Spell']/nwn:SCALAR/attribute::VALUE"/>
	        </xsl:call-template>
		  </td>
		  <td>
		    <xsl:value-of select="nwn:OBJECT[@NAME='SpellMetaMagic']/nwn:SCALAR/attribute::VALUE"/>
		  </td>
		</tr>
	  </xsl:for-each>
      <xsl:for-each select="/nwn:UTC/nwn:OBJECT[@NAME='ClassList']/nwn:LIST/nwn:LISTITEM/nwn:OBJECT[@NAME='KnownList5']/nwn:LIST/nwn:LISTITEM">
		<tr>
		  <td>5</td>
		  <td>
	        <xsl:call-template name="nwn:SpellNumToName">
	          <xsl:with-param name="val" select="nwn:OBJECT[@NAME='Spell']/nwn:SCALAR/attribute::VALUE"/>
	        </xsl:call-template>
		  </td>
		  <td>
		    <xsl:value-of select="nwn:OBJECT[@NAME='SpellMetaMagic']/nwn:SCALAR/attribute::VALUE"/>
		  </td>
		</tr>
	  </xsl:for-each>
      <xsl:for-each select="/nwn:UTC/nwn:OBJECT[@NAME='ClassList']/nwn:LIST/nwn:LISTITEM/nwn:OBJECT[@NAME='KnownList6']/nwn:LIST/nwn:LISTITEM">
		<tr>
		  <td>6</td>
		  <td>
	        <xsl:call-template name="nwn:SpellNumToName">
	          <xsl:with-param name="val" select="nwn:OBJECT[@NAME='Spell']/nwn:SCALAR/attribute::VALUE"/>
	        </xsl:call-template>
		  </td>
		  <td>
		    <xsl:value-of select="nwn:OBJECT[@NAME='SpellMetaMagic']/nwn:SCALAR/attribute::VALUE"/>
		  </td>
		</tr>
	  </xsl:for-each>
      <xsl:for-each select="/nwn:UTC/nwn:OBJECT[@NAME='ClassList']/nwn:LIST/nwn:LISTITEM/nwn:OBJECT[@NAME='KnownList7']/nwn:LIST/nwn:LISTITEM">
		<tr>
		  <td>7</td>
		  <td>
	        <xsl:call-template name="nwn:SpellNumToName">
	          <xsl:with-param name="val" select="nwn:OBJECT[@NAME='Spell']/nwn:SCALAR/attribute::VALUE"/>
	        </xsl:call-template>
		  </td>
		  <td>
		    <xsl:value-of select="nwn:OBJECT[@NAME='SpellMetaMagic']/nwn:SCALAR/attribute::VALUE"/>
		  </td>
		</tr>
	  </xsl:for-each>
      <xsl:for-each select="/nwn:UTC/nwn:OBJECT[@NAME='ClassList']/nwn:LIST/nwn:LISTITEM/nwn:OBJECT[@NAME='KnownList8']/nwn:LIST/nwn:LISTITEM">
		<tr>
		  <td>8</td>
		  <td>
	        <xsl:call-template name="nwn:SpellNumToName">
	          <xsl:with-param name="val" select="nwn:OBJECT[@NAME='Spell']/nwn:SCALAR/attribute::VALUE"/>
	        </xsl:call-template>
		  </td>
		  <td>
		    <xsl:value-of select="nwn:OBJECT[@NAME='SpellMetaMagic']/nwn:SCALAR/attribute::VALUE"/>
		  </td>
		</tr>
	  </xsl:for-each>
      <xsl:for-each select="/nwn:UTC/nwn:OBJECT[@NAME='ClassList']/nwn:LIST/nwn:LISTITEM/nwn:OBJECT[@NAME='KnownList9']/nwn:LIST/nwn:LISTITEM">
		<tr>
		  <td>9</td>
		  <td>
	        <xsl:call-template name="nwn:SpellNumToName">
	          <xsl:with-param name="val" select="nwn:OBJECT[@NAME='Spell']/nwn:SCALAR/attribute::VALUE"/>
	        </xsl:call-template>
		  </td>
		  <td>
		    <xsl:value-of select="nwn:OBJECT[@NAME='SpellMetaMagic']/nwn:SCALAR/attribute::VALUE"/>
		  </td>
		</tr>
	  </xsl:for-each>
	</table>
  </xsl:template>

  <xsl:template name="nwn:MemorizedSpells">
	<h2>Memorized Spells</h2>
	<table>
	  <tr>
	    <th>Level</th><th>Spell</th><th>Metamagic</th>
	  </tr>
      <xsl:for-each select="/nwn:UTC/nwn:OBJECT[@NAME='ClassList']/nwn:LIST/nwn:LISTITEM/nwn:OBJECT[@NAME='MemorizedList0']/nwn:LIST/nwn:LISTITEM">
		<tr>
		  <td>0</td>
		  <td>
	        <xsl:call-template name="nwn:SpellNumToName">
	          <xsl:with-param name="val" select="nwn:OBJECT[@NAME='Spell']/nwn:SCALAR/attribute::VALUE"/>
	        </xsl:call-template>
		  </td>
		  <td>
		    <xsl:value-of select="nwn:OBJECT[@NAME='SpellMetaMagic']/nwn:SCALAR/attribute::VALUE"/>
		  </td>
		</tr>
	  </xsl:for-each>
      <xsl:for-each select="/nwn:UTC/nwn:OBJECT[@NAME='ClassList']/nwn:LIST/nwn:LISTITEM/nwn:OBJECT[@NAME='MemorizedList1']/nwn:LIST/nwn:LISTITEM">
		<tr>
		  <td>1</td>
		  <td>
	        <xsl:call-template name="nwn:SpellNumToName">
	          <xsl:with-param name="val" select="nwn:OBJECT[@NAME='Spell']/nwn:SCALAR/attribute::VALUE"/>
	        </xsl:call-template>
		  </td>
		  <td>
		    <xsl:value-of select="nwn:OBJECT[@NAME='SpellMetaMagic']/nwn:SCALAR/attribute::VALUE"/>
		  </td>
		</tr>
	  </xsl:for-each>
      <xsl:for-each select="/nwn:UTC/nwn:OBJECT[@NAME='ClassList']/nwn:LIST/nwn:LISTITEM/nwn:OBJECT[@NAME='MemorizedList2']/nwn:LIST/nwn:LISTITEM">
		<tr>
		  <td>2</td>
		  <td>
	        <xsl:call-template name="nwn:SpellNumToName">
	          <xsl:with-param name="val" select="nwn:OBJECT[@NAME='Spell']/nwn:SCALAR/attribute::VALUE"/>
	        </xsl:call-template>
		  </td>
		  <td>
		    <xsl:value-of select="nwn:OBJECT[@NAME='SpellMetaMagic']/nwn:SCALAR/attribute::VALUE"/>
		  </td>
		</tr>
	  </xsl:for-each>
      <xsl:for-each select="/nwn:UTC/nwn:OBJECT[@NAME='ClassList']/nwn:LIST/nwn:LISTITEM/nwn:OBJECT[@NAME='MemorizedList3']/nwn:LIST/nwn:LISTITEM">
		<tr>
		  <td>3</td>
		  <td>
	        <xsl:call-template name="nwn:SpellNumToName">
	          <xsl:with-param name="val" select="nwn:OBJECT[@NAME='Spell']/nwn:SCALAR/attribute::VALUE"/>
	        </xsl:call-template>
		  </td>
		  <td>
		    <xsl:value-of select="nwn:OBJECT[@NAME='SpellMetaMagic']/nwn:SCALAR/attribute::VALUE"/>
		  </td>
		</tr>
	  </xsl:for-each>
      <xsl:for-each select="/nwn:UTC/nwn:OBJECT[@NAME='ClassList']/nwn:LIST/nwn:LISTITEM/nwn:OBJECT[@NAME='MemorizedList4']/nwn:LIST/nwn:LISTITEM">
		<tr>
		  <td>4</td>
		  <td>
	        <xsl:call-template name="nwn:SpellNumToName">
	          <xsl:with-param name="val" select="nwn:OBJECT[@NAME='Spell']/nwn:SCALAR/attribute::VALUE"/>
	        </xsl:call-template>
		  </td>
		  <td>
		    <xsl:value-of select="nwn:OBJECT[@NAME='SpellMetaMagic']/nwn:SCALAR/attribute::VALUE"/>
		  </td>
		</tr>
	  </xsl:for-each>
      <xsl:for-each select="/nwn:UTC/nwn:OBJECT[@NAME='ClassList']/nwn:LIST/nwn:LISTITEM/nwn:OBJECT[@NAME='MemorizedList5']/nwn:LIST/nwn:LISTITEM">
		<tr>
		  <td>5</td>
		  <td>
	        <xsl:call-template name="nwn:SpellNumToName">
	          <xsl:with-param name="val" select="nwn:OBJECT[@NAME='Spell']/nwn:SCALAR/attribute::VALUE"/>
	        </xsl:call-template>
		  </td>
		  <td>
		    <xsl:value-of select="nwn:OBJECT[@NAME='SpellMetaMagic']/nwn:SCALAR/attribute::VALUE"/>
		  </td>
		</tr>
	  </xsl:for-each>
      <xsl:for-each select="/nwn:UTC/nwn:OBJECT[@NAME='ClassList']/nwn:LIST/nwn:LISTITEM/nwn:OBJECT[@NAME='MemorizedList6']/nwn:LIST/nwn:LISTITEM">
		<tr>
		  <td>6</td>
		  <td>
	        <xsl:call-template name="nwn:SpellNumToName">
	          <xsl:with-param name="val" select="nwn:OBJECT[@NAME='Spell']/nwn:SCALAR/attribute::VALUE"/>
	        </xsl:call-template>
		  </td>
		  <td>
		    <xsl:value-of select="nwn:OBJECT[@NAME='SpellMetaMagic']/nwn:SCALAR/attribute::VALUE"/>
		  </td>
		</tr>
	  </xsl:for-each>
      <xsl:for-each select="/nwn:UTC/nwn:OBJECT[@NAME='ClassList']/nwn:LIST/nwn:LISTITEM/nwn:OBJECT[@NAME='MemorizedList7']/nwn:LIST/nwn:LISTITEM">
		<tr>
		  <td>7</td>
		  <td>
	        <xsl:call-template name="nwn:SpellNumToName">
	          <xsl:with-param name="val" select="nwn:OBJECT[@NAME='Spell']/nwn:SCALAR/attribute::VALUE"/>
	        </xsl:call-template>
		  </td>
		  <td>
		    <xsl:value-of select="nwn:OBJECT[@NAME='SpellMetaMagic']/nwn:SCALAR/attribute::VALUE"/>
		  </td>
		</tr>
	  </xsl:for-each>
      <xsl:for-each select="/nwn:UTC/nwn:OBJECT[@NAME='ClassList']/nwn:LIST/nwn:LISTITEM/nwn:OBJECT[@NAME='MemorizedList8']/nwn:LIST/nwn:LISTITEM">
		<tr>
		  <td>8</td>
		  <td>
	        <xsl:call-template name="nwn:SpellNumToName">
	          <xsl:with-param name="val" select="nwn:OBJECT[@NAME='Spell']/nwn:SCALAR/attribute::VALUE"/>
	        </xsl:call-template>
		  </td>
		  <td>
		    <xsl:value-of select="nwn:OBJECT[@NAME='SpellMetaMagic']/nwn:SCALAR/attribute::VALUE"/>
		  </td>
		</tr>
	  </xsl:for-each>
      <xsl:for-each select="/nwn:UTC/nwn:OBJECT[@NAME='ClassList']/nwn:LIST/nwn:LISTITEM/nwn:OBJECT[@NAME='MemorizedList9']/nwn:LIST/nwn:LISTITEM">
		<tr>
		  <td>9</td>
		  <td>
	        <xsl:call-template name="nwn:SpellNumToName">
	          <xsl:with-param name="val" select="nwn:OBJECT[@NAME='Spell']/nwn:SCALAR/attribute::VALUE"/>
	        </xsl:call-template>
		  </td>
		  <td>
		    <xsl:value-of select="nwn:OBJECT[@NAME='SpellMetaMagic']/nwn:SCALAR/attribute::VALUE"/>
		  </td>
		</tr>
	  </xsl:for-each>
	</table>
  </xsl:template>

  <xsl:template name="nwn:BodyParts">
    <table>
	  <tr>
	    <th>Body Part</th>
		<th>Value</th>
	  </tr>
	  <tr>
	    <td>Right Foot</td>
		<td>
		  <xsl:value-of select="/nwn:UTC/nwn:OBJECT[@NAME='ArmorPart_RFoot']/nwn:SCALAR/attribute::VALUE"/>
		</td>
	  </tr>
	  <tr>
	    <td>Left Foot</td>
		<td>
		  <xsl:value-of select="/nwn:UTC/nwn:OBJECT[@NAME='BodyPart_LFoot']/nwn:SCALAR/attribute::VALUE"/>
		</td>
	  </tr>
	  <tr>
	    <td>Right Shin</td>
		<td>
		  <xsl:value-of select="/nwn:UTC/nwn:OBJECT[@NAME='BodyPart_RShin']/nwn:SCALAR/attribute::VALUE"/>
		</td>
	  </tr>
	  <tr>
	    <td>Left Shin</td>
		<td>
		  <xsl:value-of select="/nwn:UTC/nwn:OBJECT[@NAME='BodyPart_LShin']/nwn:SCALAR/attribute::VALUE"/>
		</td>
	  </tr>
	  <tr>
	    <td>Right Thigh</td>
		<td>
		  <xsl:value-of select="/nwn:UTC/nwn:OBJECT[@NAME='BodyPart_RThigh']/nwn:SCALAR/attribute::VALUE"/>
		</td>
	  </tr>
	  <tr>
	    <td>Left Thigh</td>
		<td>
		  <xsl:value-of select="/nwn:UTC/nwn:OBJECT[@NAME='BodyPart_LThigh']/nwn:SCALAR/attribute::VALUE"/>
		</td>
	  </tr>
	  <tr>
	    <td>Pelvis</td>
		<td>
		  <xsl:value-of select="/nwn:UTC/nwn:OBJECT[@NAME='BodyPart_Pelvis']/nwn:SCALAR/attribute::VALUE"/>
		</td>
	  </tr>
	  <tr>
	    <td>Belt</td>
		<td>
		  <xsl:value-of select="/nwn:UTC/nwn:OBJECT[@NAME='BodyPart_Belt']/nwn:SCALAR/attribute::VALUE"/>
		</td>
	  </tr>
	  <tr>
	    <td>Torso</td>
		<td>
		  <xsl:value-of select="/nwn:UTC/nwn:OBJECT[@NAME='BodyPart_Torso']/nwn:SCALAR/attribute::VALUE"/>
		</td>
	  </tr>
	  <tr>
	    <td>Neck</td>
		<td>
		  <xsl:value-of select="/nwn:UTC/nwn:OBJECT[@NAME='BodyPart_Neck']/nwn:SCALAR/attribute::VALUE"/>
		</td>
	  </tr>
	  <tr>
	    <td>Head</td>
		<td>
		  <xsl:value-of select="/nwn:UTC/nwn:OBJECT[@NAME='Appearance_Head']/nwn:SCALAR/attribute::VALUE"/>
		</td>
	  </tr>
	  <tr>
	    <td>Right Hand</td>
		<td>
		  <xsl:value-of select="/nwn:UTC/nwn:OBJECT[@NAME='BodyPart_RHand']/nwn:SCALAR/attribute::VALUE"/>
		</td>
	  </tr>
	  <tr>
	    <td>Left Hand</td>
		<td>
		  <xsl:value-of select="/nwn:UTC/nwn:OBJECT[@NAME='BodyPart_LHand']/nwn:SCALAR/attribute::VALUE"/>
		</td>
	  </tr>
	  <tr>
	    <td>Right Forearm</td>
		<td>
		  <xsl:value-of select="/nwn:UTC/nwn:OBJECT[@NAME='BodyPart_RFArm']/nwn:SCALAR/attribute::VALUE"/>
		</td>
	  </tr>
	  <tr>
	    <td>Left Forearm</td>
		<td>
		  <xsl:value-of select="/nwn:UTC/nwn:OBJECT[@NAME='BodyPart_LFArm']/nwn:SCALAR/attribute::VALUE"/>
		</td>
	  </tr>
	  <tr>
	    <td>Right Bicep</td>
		<td>
		  <xsl:value-of select="/nwn:UTC/nwn:OBJECT[@NAME='BodyPart_RBicep']/nwn:SCALAR/attribute::VALUE"/>
		</td>
	  </tr>
	  <tr>
	    <td>Left Bicep</td>
		<td>
		  <xsl:value-of select="/nwn:UTC/nwn:OBJECT[@NAME='BodyPart_LBicep']/nwn:SCALAR/attribute::VALUE"/>
		</td>
	  </tr>
	  <tr>
	    <td>Right Shoulder</td>
		<td>
		  <xsl:value-of select="/nwn:UTC/nwn:OBJECT[@NAME='BodyPart_RShoul']/nwn:SCALAR/attribute::VALUE"/>
		</td>
	  </tr>
	  <tr>
	    <td>Left Shoulder</td>
		<td>
		  <xsl:value-of select="/nwn:UTC/nwn:OBJECT[@NAME='BodyPart_LShoul']/nwn:SCALAR/attribute::VALUE"/>
		</td>
	  </tr>
	  <tr>
	  </tr>
	  <tr>
	    <td>Skin Color</td>
		<td>
		  <xsl:value-of select="/nwn:UTC/nwn:OBJECT[@NAME='Color_Skin']/nwn:SCALAR/attribute::VALUE"/>
		</td>
	  </tr>
	  <tr>
	    <td>Hair Color</td>
		<td>
		  <xsl:value-of select="/nwn:UTC/nwn:OBJECT[@NAME='Color_Hair']/nwn:SCALAR/attribute::VALUE"/>
		</td>
	  </tr>
	  <tr>
	    <td>Tattoo1 Color</td>
		<td>
		  <xsl:value-of select="/nwn:UTC/nwn:OBJECT[@NAME='Color_Tattoo1']/nwn:SCALAR/attribute::VALUE"/>
		</td>
	  </tr>
	  <tr>
	    <td>Tattoo2 Color</td>
		<td>
		  <xsl:value-of select="/nwn:UTC/nwn:OBJECT[@NAME='Color_Tattoo2']/nwn:SCALAR/attribute::VALUE"/>
		</td>
	  </tr>
	</table>
  </xsl:template>

</xsl:stylesheet>
