/*
 * SporthControlDialog.cpp - control dialog for Sporth
 *
 * Copyright (c) 2017 Paul Batchelor
 *
 * This file is part of LMMS - http://lmms.io
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program (see COPYING); if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA.
 *
 */

#include <QLayout>
#include <iostream>

#include "SporthControlDialog.h"
#include "SporthControls.h"
#include "embed.h"

SporthControlDialog::SporthControlDialog( SporthControls* controls ) :
	EffectControlDialog( controls )
{
	setAutoFillBackground( true );
	QPalette pal;
	pal.setBrush( backgroundRole(), PLUGIN_NAME::getIconPixmap( "artwork" ) );
	setPalette( pal );
	setFixedSize( 500, 500 );
	
	Knob * inputGainKnob = new Knob( knobBright_26, this);
	inputGainKnob -> move( 16, 10 );
	inputGainKnob->setModel( &controls->m_inputGainModel );
	inputGainKnob->setLabel( tr( "Input" ) );
	inputGainKnob->setHintText( tr( "Input Gain:" ) , "dB" );

	Knob * sizeKnob = new Knob( knobBright_26, this);
	sizeKnob -> move( 57, 10 );
	sizeKnob->setModel( &controls->m_sizeModel );
	sizeKnob->setLabel( tr( "Size" ) );
	sizeKnob->setHintText( tr( "Size:" ) , "" );

	Knob * colorKnob = new Knob( knobBright_26, this);
	colorKnob -> move( 98, 10 );
	colorKnob->setModel( &controls->m_colorModel );
	colorKnob->setLabel( tr( "Color" ) );
	colorKnob->setHintText( tr( "Color:" ) , "" );

	//Knob * outputGainKnob = new Knob( knobBright_26, this);
	//outputGainKnob -> move( 139, 10 );
	//outputGainKnob->setModel( &controls->m_outputGainModel );
	//outputGainKnob->setLabel( tr( "Output" ) );
	//outputGainKnob->setHintText( tr( "Output Gain:" ) , "dB" );

    LedCheckBox *but  = new LedCheckBox(this, tr("compile"));
    but->move( 139, 10 );
    but->setModel(&controls->m_compileModel);

    controls->textEditor = new QPlainTextEdit(this);
    controls->textEditor->move(16, 50);
    controls->textEditor->resize(180, 90);
    
    std::string txt = controls->sporth_string.toUtf8().constData();
    std::cout << "dialogue " << txt << "\n";
    controls->textEditor->document()->setPlainText(controls->sporth_string);
}
